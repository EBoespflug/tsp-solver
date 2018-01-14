/**
 * MainWindow_core.cpp
 * Etienne Boespflug - 2017
 */

#include "MainWindow.hpp"

#include "GraphWidget.hpp"
#include "../Core/GeneticAlgorithm.hpp"

#include <random>
#include <iostream>
#include <vector>
#include <QSpinBox>
#include <QCheckBox>
#include "qdebug.h"

void MainWindow::runGA()
{
    // Getting parameters.
    auto popCount = static_cast<unsigned>(populationSpinBox_->value());
    auto generationCount = static_cast<unsigned>(generationCount_->value());

    auto mutation = enableElitismCheckBox_->isChecked();
    auto crossover = enableElitismCheckBox_->isChecked();
    auto elitism = enableElitismCheckBox_->isChecked();

    auto mutationRate = static_cast<float>(mutationPercentSpinBox_->value());
    auto crossoverRate = static_cast<float>(crossoverPercentSpinBox_->value());
    auto mutationElitism = static_cast<unsigned>(elitismCrossover_->value());
    auto crossoverElitism = static_cast<unsigned>(elitismKeeped_->value());

    // % to float and check if enabled.
    (!mutation) ? mutationRate = 0 : mutationRate  = mutationRate / 100.f;
    (!crossover) ? crossoverRate = 0 : crossoverRate  = crossoverRate / 100.f;
    if (!elitism) {
        mutationElitism = 0;
        crossoverElitism = 0;
    }

    GeneticAlgorithm::GAParams params{mutationRate, crossoverRate, mutationElitism, crossoverElitism};

    GeneticAlgorithm ga{nodes_, popCount, params};

    for(auto i = 0u; i < generationCount; ++i) {
        ga.evolve();
    }

    std::cout << "Result = " << ga.bestIndividual().toString();
    std::cout << " - distance = " << ga.bestIndividual().distance() << std::endl;
    graphWidget_->setGAEdges(ga.bestIndividual().getCircuit());
}

void MainWindow::generateNodes()
{
    const double minX{ - (graphSizeX_->value() / 2.) };
    const double maxX{ graphSizeX_->value() / 2. };
    const double minY{ - (graphSizeY_->value() / 2.) };
    const double maxY{ graphSizeY_->value() / 2. };
    const unsigned count{ static_cast<unsigned>(graphItemCount_->value()) };

    static std::random_device rd;
    static std::mt19937 g(rd());
    std::uniform_real_distribution<double> distX(minX, maxX);
    std::uniform_real_distribution<double> distY(minY, maxY);

    nodes_.clear();
    for(auto i = 0u; i < count; ++i)
    {
        double posX{ distX(g) };
        double posY{ distY(g) };
        nodes_.push_back(Node{posX, posY, "City " + std::to_string(i)});
    }

    graphWidget_->setNodes(nodes_);
    graphWidget_->adjustSceneRect();
}
