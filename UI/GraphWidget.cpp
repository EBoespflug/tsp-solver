/**
 * GraphWidget.cpp
 * Etienne Boespflug - 2017
 *
 * Inspired by the Qt's example http://doc.qt.io/qt-5/qtwidgets-graphicsview-elasticnodes-example.html
 */

#include "GraphWidget.hpp"
#include "GUIEdge.hpp"
#include "GUINode.hpp"

#include <cmath>

#include <QKeyEvent>

GraphWidget::GraphWidget(QWidget* parent)
    : QGraphicsView(parent)
{
    scene_ = new QGraphicsScene(this);
    scene_->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene_);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(1), qreal(1));
    setMinimumSize(400, 400);
}

void GraphWidget::adjustSceneRect()
{
    scene_->setSceneRect(scene_->itemsBoundingRect());
}

void GraphWidget::setNodes(const std::vector<Node>& nodes)
{
    scene_->clear();
    nodes_.clear();
    gaEdges_.clear();

    for(auto& n : nodes)
    {
        GUINode* node = new GUINode(this);
        node->setPos(n.x, n.y);
        scene_->addItem(node);
        nodes_.insert(std::make_pair(n.tag, node));
    }
}

void GraphWidget::clearEdges()
{
    for(auto edge : gaEdges_)
        scene_->removeItem(edge);
    gaEdges_.clear();
}

void GraphWidget::setGAEdges(const std::vector<Node>& circuit)
{
    clearEdges();
    for(auto i = 0u; i < circuit.size() - 1; ++i) {
        auto n1 = nodes_[circuit[i].tag];
        auto n2 = nodes_[circuit[i + 1].tag];
        GUIEdge* edge = new GUIEdge(n1, n2);
        scene_->addItem(edge);
        gaEdges_.push_back(edge);
    }
}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(1.0/(pow(2., -event->delta() / 240.0)));
}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);
}

void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void GraphWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

void GraphWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}
