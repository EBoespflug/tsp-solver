/**
 * GUIEdge.hpp
 * Etienne Boespflug - 2017
 *
 * Inspired by the Qt's example http://doc.qt.io/qt-5/qtwidgets-graphicsview-elasticnodes-example.html
 */

#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>

class GUINode;

/**
 * @brief The GUIEdge class represent an edge in the GUI scene.
 *
 * An edge connects two nodes and is always directed.
 */
class GUIEdge : public QGraphicsItem
{
public:
    /**
     * Creates a new GUIEdge with the specified destination
     *  and source nodes (cities).
     * @param sourceGUINode the origin node.
     * @param destGUINode the destination node.
     */
    GUIEdge(GUINode* sourceGUINode, GUINode* destGUINode);

    /**
     * @return the source node of the edge.
     */
    GUINode* sourceGUINode() const;

    /**
     * @return the destination node of the edge.
     */
    GUINode* destGUINode() const;

    /**
     * Refresh the position of the edge depending on the node position.
     */
    void adjust();

    /**
     * @return the type identifier of this scene item.
     */
    int type() const override { return UserType + 2; }

protected:
    /**
     * @return the bouding rect of the item.
     */
    QRectF boundingRect() const override;
    /**
     * Paints the edge (line + arrow).
     * @param painter the QPainter used to paint the GUIEdge.
     * @param option the painting options.
     * @param widget the corresponding widget.
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    /** The source node of the edge. */
    GUINode* source;
    /** The destination node of the edge. */
    GUINode* dest;

    /** The source point of the edge. */
    QPointF sourcePoint;
    /** The destination point of the edge. */
    QPointF destPoint;
    /** The size of the arrow at the end of the edge. */
    qreal arrowSize;
};

#endif // EDGE_H
