/**
 * GeneticAlgorithm.cpp
 * Etienne Boespflug - 2017
 */

#include "GeneticAlgorithm.hpp"

#include <random>
#include <algorithm>
#include <cassert>
#include <iostream>

#include "Population.hpp"

static std::random_device rd;
static std::mt19937 g(rd());

GeneticAlgorithm::GeneticAlgorithm(const std::vector<Node>& cities, std::size_t populationSize, const GAParams& params) :
    cities_{ cities },
    population_(cities, populationSize),
    params_{ params }
{

}

Individual GeneticAlgorithm::bestIndividual()
{
    return population_.bestFitnessIndividual();
}

void GeneticAlgorithm::evolve()
{
    population_.sort();

    auto elitismOffsetMutate= static_cast<size_t>(population_.size() * params_.mutationElitismCount);
    auto elitismOffsetReprod = static_cast<size_t>(population_.size() * params_.crossoverElitismCount);

    // Can actually use childs as parent.
    std::uniform_real_distribution<float> rate(0, 1.f);
    for(auto i = elitismOffsetReprod; i < population_.size(); ++i) {
        if(rate(rd) > params_.crossoverRate)
            continue;
        auto parent1 = select();
        auto parent2 = select();

        auto individual = crossover(parent1, parent2);
        population_.setIndividual(i, individual);
    }

    for(auto i = elitismOffsetMutate; i < population_.size(); ++i)
        mutate(population_.getIndividual(i));
}

Individual GeneticAlgorithm::crossover(const Individual& parent1, const Individual& parent2) const
{
    std::uniform_int_distribution<unsigned long> dist(0, parent1.size() - 1);

    auto crossPos = dist(g);

    std::vector<Node> circuit;
    circuit.reserve(parent1.size());

    for(auto i = 0u; i < crossPos; ++i)
        circuit.push_back(parent1.getNode(i));

    for(auto i = 0u; i < parent2.size(); ++i)
    {
        auto it = std::find(circuit.begin(), circuit.end(), parent2.getNode(i));
        if(it == circuit.end())
            circuit.push_back(parent2.getNode(i));
    }

    assert(circuit.size() == parent1.size() && "Internal errror");

    auto i = Individual(circuit, false);
    return i;
}

void GeneticAlgorithm::mutate(Individual& individual)
{
    std::uniform_int_distribution<std::size_t> dist(0, individual.size() - 1);
    std::uniform_real_distribution<float> rate(0, 1.f);

    if(rate(g) < params_.mutationRate) // Mutate
    {
        auto pos1 = dist(g);
        auto pos2 = dist(g);

        auto n1 = individual.getNode(pos1);
        auto n2 = individual.getNode(pos2);

        individual.setNode(n2, pos1);
        individual.setNode(n1, pos2);
    }
}

Individual GeneticAlgorithm::select()
{
    // Tournament selection.
    const unsigned count = 5;
    std::uniform_int_distribution<unsigned long> dist(0, population_.size() - 1);

    std::vector<Individual> tournament;
    for(auto i = 0u; i < count; ++i)
        tournament.push_back(population_.getIndividual(dist(g)));

    std::sort(tournament.begin(), tournament.end(), [](const Individual& i1, const Individual& i2) {
       return i1.distance() < i2.distance();
    });

    return tournament[0];
}

void GeneticAlgorithm::assertParams(const GAParams& params)
{
    assert(params.crossoverRate < 1.0 && params.crossoverRate >= 0 && "The crossover rate should be in [0, 1].");
    assert(params.mutationRate < 1.0 && params.mutationRate >= 0 && "The crossover rate should be in [0, 1].");
    assert(params.crossoverElitismCount <= population_.size() && "The elitism for the crossover shouldn't be greater than the population size");
    assert(params.mutationElitismCount <= population_.size() && "The elitism for the mutation shouldn't be greater than the population size");
}
