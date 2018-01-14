/**
 * GUINode.hpp
 * Etienne Boespflug - 2017
 *
 * Inspired by the Qt's example http://doc.qt.io/qt-5/qtwidgets-graphicsview-elasticnodes-example.html
 */

#ifndef GUINODE_HPP
#define GUINODE_HPP

#include <QGraphicsItem>
#include <QList>

class GUIEdge;
class GraphWidget;
class QGraphicsSceneMouseEvent;

/**
 * @brief The GUINode class represent a node (a city)
 *  in the 2D graphic scene.
 *
 * The node can be moved.
 * TODO() change the corresponding node coordinate when
 *  a GUINode is moved. Maybe add a descriptive panel.
 */
class GUINode : public QGraphicsItem
{
public:
    /**
     * Create a new GUINode in the specified graph
     *  widget.
     * @param graphWidget
     */
    GUINode(GraphWidget* graphWidget);

    void addGUIEdge(GUIEdge* edge);
    QList<GUIEdge*> edges() const;

    /**
     * @return the type identifier of this scene item.
     */
    int type() const override { return UserType + 1; }

    /**
     * Advance the item to newPos.
     * @return true if the position changed.
     */
    bool advance();

    /**
     * @return the bouding rect of the item.
     */
    QRectF boundingRect() const override;
    /**
     * @return the path of the shape for the painter.
     */
    QPainterPath shape() const override;
    /**
     * Paints the node (circle + shadow).
     * @param painter the QPainter used to paint the GUIEdge.
     * @param option the painting options.
     * @param widget the corresponding widget.
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

protected:
    /**
     * Adjust the edge of the node if the position has changed.
     * @param change the current change.
     * @param value  the value of the change.
     * @return the item change.
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

    /**
     * Update the item on mouse press.
     * @param event the mouse event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    /**
     * Update the item on mouse release.
     * @param event the mouse event.
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
    /** The list of edge (in/out). Used to refresh edge on move. */
    QList<GUIEdge*> edgeList;
    /** The new position of the item on move. */
    QPointF newPos;
    /** The GraphiWidget containing the node. */
    GraphWidget* graph;
};

#endif // GUINODE_HPP
