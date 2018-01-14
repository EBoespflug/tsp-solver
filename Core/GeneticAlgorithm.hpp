/**
 * GeneticAlgorithm.hpp
 * Etienne Boespflug - 2017
 */

#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include <vector>

#include "Node.hpp"
#include "Population.hpp"

class Individual;

/**
 * @brief The GeneticAlgorithm class represent a genetic algorithm wich holds
 *  the algorithm parameters, the population and provides the commun GA's
 *  features (mutate, evolve, crossover, select...).
 */
class GeneticAlgorithm
{
    /** The list of the Nodes (cities) of the TSP. */
    const std::vector<Node>& cities_;
    /** The population of the algorithm */
    Population population_;

public:
    /**
     * The GAParams struct holds the parameters of the genetic
     *  algorithm.
     */
    struct GAParams {
        GAParams(float mR, float cR, std::size_t mEC, std::size_t cEC)
            : mutationRate{ mR }, crossoverRate{ cR },
              mutationElitismCount{ mEC }, crossoverElitismCount{ cEC } {}
        /** The rate of mutation per generation. */
        float mutationRate = 0.1f;
        /** The rate of crossover per generation. */
        float crossoverRate = 0.2f;
        /**
         * The number of elite individual keeped on mutation.
         *  Should be lower than the population count.
         */
        std::size_t mutationElitismCount = 0u;
        /**
         * The number of elite individuals keeped on crossover.
         *  Should be lower than the population count.
         */
        std::size_t crossoverElitismCount = 0u;
    };

    /**
     * @brief Constructs a new object with the specified parameters.
     *
     * @param cities the list of the nodes (cities) of the TSP.
     * @param populationSize the fixed population size of the algorithm.
     * @param params the parameters of the algorithm.
     */
    GeneticAlgorithm(const std::vector<Node>& cities, std::size_t populationSize, const GAParams& params);
    /**
     * @brief cross two specified individual and return the new child.
     * @param parent1 the first parent of the crossover.
     * @param parent2 the second parent of the crossover.
     * @return a child from the two parents.
     */
    Individual crossover(const Individual& parent1, const Individual& parent2) const;
    /**
     * @brief mutates the specified individual. Swap two cities in the individual's
     *  path.
     * @param individual the individual to be mutated.
     */
    void mutate(Individual& individual);
    /**
     * @brief runs a step of the genetic algorithm (mutation and crossover with the
     *  specified selection mode.
     */
    void evolve();
    /**
     * @return the string representation of the population of the algoritm.
     */
    std::string toString() { population_.sort(); return population_.toString(); }
    /**
     * @return an individual selected in the population (appling tournament selection).
     */
    Individual select();
    /**
     * @return the best individual of the population (i.e. the individual with
     *  the best fitness).
     */
    Individual bestIndividual();

private:
    /**
     * Make assertion on the value of the parameters (removed in release).
     * @param params the parameters of the algorithm.
     */
    inline void assertParams(const GAParams& params);
    /**
     * The parameters of the algorithm.
     */
    GAParams params_;
};

#endif // GENETICALGORITHM_HPP
