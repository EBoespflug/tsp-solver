/**
 * Population.hpp
 * Etienne Boespflug - 2017
 */

#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <vector>
#include <string>
#include "Individual.hpp"

/**
 * @brief The Population class represent a population for a genetic
 *  algorithm (GA).
 *
 * It holds the list of the invidivuals of the population.
 *
 * The individual are referenced by the index in the list. The GA
 *  use the sorted list of individual to provide elitism feature.
 */
class Population
{
public:
    /**
     * Creates a Population with the specified size and cities (random
     *  individuals).
     * @param cities the list of node (cities) of the TSP.
     * @param size the fixed size of the population.
     */
    Population(const std::vector<Node>& cities, std::size_t size);

    /**
     * @return the individual with the best fitness (lowest distance).
     */
    const Individual& bestFitnessIndividual();
    /**
     * Set the individual a the specified index to the passed value.
     * @param index the index identifying the individual in the
     *  population.
     * @param individual the individual to be placed at this index.
     */
    void setIndividual(std::size_t index, Individual individual);
    /**
     * Returns the individual at the specified index.
     * @param index
     * @return
     */
    Individual& getIndividual(std::size_t index);
    /**
     * Sorts the list of individual (decreasing).
     */
    void sort();
    /**
     * @return the size of the population (constant).
     */
    std::size_t size() const { return individuals_.size(); }
    /**
     * @return the string representation of the population (size
     *  and individuals).
     */
    std::string toString() const;

private:
    /** The list of the individuals of the population. */
    std::vector<Individual> individuals_;
};

#endif // POPULATION_HPP
