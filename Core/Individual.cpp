/**
 * Individual.cpp
 * Etienne Boespflug - 2017
 */

#include "Individual.hpp"
#include "Node.hpp"

#include <random>
#include <algorithm>
#include <cassert>

Individual::Individual(const std::vector<Node>& cities, bool shuffle) :
    circuit(cities.begin(), cities.end())
{
    assert(cities.size() != 0 && "Empty cities.");
    static std::random_device rd;
    static std::mt19937 g(rd());
    if(shuffle)
        std::shuffle(circuit.begin(), circuit.end(), g);
}

std::string Individual::toString() const
{
    std::string ret = "{";
    for(auto c : circuit)
        ret += "(" + c.tag + "), ";
    ret += "[end]}";
    return ret;
}

Node Individual::getNode(std::size_t index) const
{
    assert(circuit.size() > index && "Index out of range.");

    return circuit[index];
}

void Individual::setNode(Node n, std::size_t index)
{
    assert(circuit.size() > index && "Index out of range.");

    circuit[index] = n;
}

double Individual::distance() const
{
    double distance{};
    for(size_t i{ 0u }; i < circuit.size() - 1; ++i)
        distance += Node::distance(circuit[i], circuit[i + 1]);
    distance += Node::distance(*circuit.end(), *circuit.end());

    return distance;
}

double Individual::fitness() const
{
    double d = distance();
    if(d == 0.0)
        return 0.0;
    return 1 / d;
}
