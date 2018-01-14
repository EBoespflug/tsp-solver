/**
 * Individual.hpp
 * Etienne Boespflug - 2017
 */

#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include <vector>
#include <string>

#include "Node.hpp"

/**
 * @brief The Individual class represent a valid circuit of the TSP.
 *  An individual is intended to be mutated or crossed with another
 *  in a genetic algorithm.
 */
class Individual // (Circuit)
{
    /** The circuit (valid list of cities (nodes)). */
    std::vector<Node> circuit;
public:
    /**
     * @param cities the list of nodes (cities) of the TSP.
     * @param shuffle if true, shuffle the specified cities, do nothing
     *  otherwise.
     */
    Individual(const std::vector<Node>& cities, bool shuffle = true);

    /**
     * @return the size of the circuit (constant for all individual of
     *  the genetic algorithm.
     */
    std::size_t size() const { return circuit.size(); }
    /**
     * Returns the node at the specified index.
     *
     * @param index identifying the node.
     * @return the node at the specified index.
     */
    Node getNode(std::size_t index) const;
    /**
     * Set the node at the specified index to the passed node.
     * @param index identifying the node.
     */
    void setNode(Node, std::size_t index);
    /**
     * @return the total distance of the circuit.
     */
    double distance() const;
    /**
     * @return the fitness of the circuit. Equal to 1/distance.
     */
    double fitness() const;
    /**
     * @return the string representation of the individual (i.e. the list of cities).
     */
    std::string toString() const;
    /**
     * @return a copy of the circuit (list of nodes (cities)).
     */
    std::vector<Node> getCircuit() const { return circuit; }
};

#endif // INDIVIDUAL_HPP
