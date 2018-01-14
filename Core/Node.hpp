/**
 * Node.hpp
 * Etienne Boespflug - 2017
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <cmath>
#include <string>

/**
 * @brief The Node class represent a city of the TSP with a name and 2D
 *  coordinates.
 */
struct Node
{
    /**
     * Creates a new nodes with the specified name and coordinates.
     * @param x_ the first 2D coordinate.
     * @param y_ the second 2D coordinate.
     * @param tag_ the name of the node (city).
     */
    Node(double x_, double y_, const std::string& tag_) : x{x_}, y{y_}, tag{tag_} {}

    /** The first 2D coordinate. */
    double x;
    /** The second 2D coordinate. */
    double y;
    /** The name of the node (city). */
    std::string tag;

    /**
     * Returns the distance between two nodes.
     * 
     * @param n1 the first node operand.
     * @param n2 the second node operand.
     * @return the distance between the two specified nodes.
     */
    static double distance(const Node& n1, const Node& n2) {
        return std::sqrt((n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y));
    }
};

/**
 * Returns true if the two nodes are equals (same name), false
 *  otherwise.
 * 
 * @param a the first node operand.
 * @param b the second node operand.
 * @return true if the nodes has the same name, false otherwise.
 */
inline bool operator == (const Node& a, const Node& b) {
    return a.tag == b.tag;
}

#endif // NODE_HPP
