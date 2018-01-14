/**
 * GraphWidget.hpp
 * Etienne Boespflug - 2017
 *
 * Inspired by the Qt's example http://doc.qt.io/qt-5/qtwidgets-graphicsview-elasticnodes-example.html
 */

#ifndef GRAPHWIDGET_HPP
#define GRAPHWIDGET_HPP

#include <QGraphicsView>
#include <map>
#include <vector>

class GUINode;
class GUIEdge;

#include "Core/Node.hpp"

/**
 * @brief The GraphWidget class contains the graphical view of the
 *  TSP. It holds the 2D scene with the nodes and edges.
 */
class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    /**
     * Creates a new GraphWidget with the specified parent
     *  (nullptr if no parent).
     * @param parent the parent of the widget.
     */
    GraphWidget(QWidget* parent = nullptr);

public slots:
    /** Zoom in the scene (20%). */
    void zoomIn();
    /** Dezoom in the scene (20%). */
    void zoomOut();
    /**
     * Replaces the nodes (cities) list with the specified one. All edges are
     *  reset.
     * @param nodes the new nodes list.
     */
    void setNodes(const std::vector<Node>& nodes);
    /**
     * Replaces the edges list with the specified one. Old edges are deleted.
     * @param circuit the list of node used to create the edges.
     */
    void setGAEdges(const std::vector<Node>& circuit);
    /**
     * Remove all edges of the graph.
     */
    void clearEdges();
    /**
     * Set the scene size to the minimum (item bounded rect).
     */
    void adjustSceneRect();

protected:
    /**
     * Handles the '+' and '-' keys (zooms).
     * @param event the considered key event.
     */
    void keyPressEvent(QKeyEvent* event) override;
#ifndef QT_NO_WHEELEVENT
    /**
     * Handle the mouse wheel event for zoom.
     * @param event the considered wheel event.
     */
    void wheelEvent(QWheelEvent* event) override;
#endif
    /**
     * Draw the background of the scene.
     * @param painter the painter used for drawing.
     * @param rect the dimension of the background.
     */
    void drawBackground(QPainter* painter, const QRectF& rect) override;
    /**
     * Rescale the scene (used by zoom functions).
     * @param scaleFactor the factor of zoom.
     */
    void scaleView(qreal scaleFactor);

private:
    /** The scene of the graph. */
    QGraphicsScene* scene_;
    /** A map binding each node (city) name to a GUINode. */
    std::map<std::string, GUINode*> nodes_;
    /** The list of the GUIEdge between nodes. */
    std::vector<GUIEdge*> gaEdges_;
};

#endif // GRAPHWIDGET_HPP
