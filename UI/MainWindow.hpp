/**
 * GUINode.hpp
 * Etienne Boespflug - 2017
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QSettings>

class GraphWidget;
class QSpinBox;
class QSlider;
class QPushButton;
class QMenu;
class QAction;
class QToolBar;
class QTabWidget;
class QComboBox;
class QDoubleSpinBox;
class QCheckBox;

#include "../Core/Node.hpp"

/**
 * @brief The MainWindow class represent the main window of
 *  the application, holding toolbars, menus and the
 *  GraphWidget (the scene).
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Create a new main window (toolbars, menus, widgets...).
     * This function generate a default graph of nodes (cities).
     *
     * @param parent the parent of the widget (nullptr
     *  for no parent).
     */
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override = default;

public slots:
    /** Quit the application. Saves settings.*/
    void quit();
    /** Open the about dialog. */
    void about();
    /** Generate the nodes (cities) depending on the selected
     *  parameters. */
    void generateNodes();
    /** Runs the genetic algorithm. */
    void runGA();

protected:
    /** Saves settings. */
    virtual void closeEvent(QCloseEvent *) override;

private:
    // Functions.
        /** Create the actions of the application. */
        inline void createActions_();
        /** Create the toolbars of the window. */
        inline void createToolBars_();
        /** Create the menus of the window. */
        inline void createMenus_();
        /** Create the widget hierarchy of the window. */
        inline void createWidgets_();

        // Settings
        /** Save the setting of the application. */
        void saveSettings();
        /** Load the setting of the application. */
        void loadSettings();

    // Core.
        /** The nodes (cities) of the TSP. */
        std::vector<Node> nodes_;
        /** The QSetting of the application. */
        QSettings settings_;

    // Widgets.
        /** The GraphWidget containing the scene. */
        GraphWidget* graphWidget_;

        /** Algorithms tab widget. */
        QTabWidget* algorithmsTab_;
            // GA
                QSpinBox* populationSpinBox_;
                QSpinBox* generationCount_;
                // Mutation
                    QCheckBox* enableMutationCheckBox_;
                    QSpinBox* mutationPercentSpinBox_;
                // Crossover
                    QCheckBox* enableCrossoverCheckBox_;
                    QSpinBox* crossoverPercentSpinBox_;
                    QComboBox* selectionMode_;
                // Elitism
                    QCheckBox* enableElitismCheckBox_;
                    QSpinBox* elitismKeeped_;
                    QSpinBox* elitismCrossover_;
                QPushButton* startGAButton_;

            // Ant colony
                QSpinBox* antCount_;
                QSpinBox* evaporationRate_;
                QDoubleSpinBox* minimumPheromone_;
                QDoubleSpinBox* maximumPheromone_;

                QPushButton* startACAButton_;

            // Graph
                QSpinBox* graphItemCount_;
                QSpinBox* graphSizeX_;
                QSpinBox* graphSizeY_;
                QPushButton* generateNodes_;

            QPushButton* startAllButton_;


    // General.

    /** Menus of the window. */
    struct {
        QMenu* file;
        QMenu* edit;
        QMenu* run;
        QMenu* view;
        QMenu* help;
    } menus_;

    /** Action of the window. */
    struct {
        // File.
        QAction* newSimulation;
        QAction* save;
        QAction* saveAs;
        QAction* quit;
        // Edit.
        QAction* generateNodes;
        // Run.
        QAction* start;
        QAction* startSBS;
        QAction* stop;
        QAction* clear;
        QAction* mutate;
        QAction* crossover;
        // View.
        struct {
            QAction* file;
            QAction* edit;
            QAction* run;
        } showTBs;
        // Help.
        QAction* help;
        QAction* about;
    } actions_;

    /** Toolbars of the window. */
    struct {
        QToolBar* file;
        QToolBar* edit;
        QToolBar* run;
    } toolbars_;
};

#endif // MAINWINDOW_HPP
