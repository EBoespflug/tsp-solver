/**
 * Population.cpp
 * Etienne Boespflug - 2017
 */

#include "Population.hpp"

#include <cassert>
#include <algorithm>

Population::Population(const std::vector<Node>& cities, std::size_t size)
{
    assert(size >= 5 && "The population size have to be greater than 5.");

    individuals_.reserve(size);
    for(auto i = 0u; i < size; ++i)
        individuals_.push_back(Individual{cities});
}

std::string Population::toString() const
{
    std::string ret = "Population : " + std::to_string(individuals_.size()) + "\n";
    for(auto& i : individuals_)
        ret += "   - (distance = " + std::to_string(i.distance()) + ") " + i.toString() + ".\n";
    return ret;
}

const Individual& Population::bestFitnessIndividual()
{
    sort();
    return individuals_[0];
}

Individual& Population::getIndividual(std::size_t index)
{
    assert(index < individuals_.size() && "Index out of range.");

    return individuals_[index];
}

void Population::setIndividual(std::size_t index, Individual individual)
{
    assert(index < individuals_.size() && "Index out of range.");

    individuals_[index] = individual;
}

void Population::sort()
{
    std::sort(individuals_.begin(), individuals_.end(), [](const Individual& a, const Individual& b) {
       return a.distance() < b.distance();
    });
}
