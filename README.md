# TSP Solver

## Overview
This tool use a genetic algorithm (and ant colony in later version) to solve the Traveler Salesman Problem (TSP). This Artificial Intelligence approache provide a non-optimal solution in an acceptable times (the TSP is NP-complete problem). This solftware is written in C++/Qt.

## Installation and Dependencies

The project is provided with the Qt Project file (.pro), open this file with QtCreator and compile the project. If you prefer to use another build system (such as make), just compile the sources.

## Usage

The following image shows an usage of the TSP solver with a simple graph (10 nodes) and the default genetic algorithm paramters.

![screenshot](https://raw.githubusercontent.com/EBoespflug/tsp-solver/master/release/screenshots/main.png)

The left pannel allows the user to change the parameters of the genetic algorithm : 
 - population count.
 - generation count.
 - mutation parameters.
 - crossover parameters.
 - elitism parameters.
 
 You can start the genetic algorithm with the **Start** button. The **Start all** start the genetic algorithm and the ant colony algorithm but the ant colony algorithm is not available for now.
 
 The left pannel also contains an interface to modify the TSP graph (cities and dimensions).

## Features and ideas

Here is a list of the feature and ideas that will (or maybe not) be implemented on the software : 
 - *Ant colony algorithm*: implementation of a ant colony algorithm to resolve the TSP.
 - *Graphical benshmark*: show (and maybe save/export graphics) about the execution time, the memory consumsion and other to compare the different algorithm and the different parameters.
 - *Movable GUI nodes*: the nodes of the graph (corresponding to the TSP nodes : the cities) could be movable. Thus, the GUINode could change the effective position of the nodes (cities).
 - *Image background*: an image can be used as background (such as an actual map) and the user can specify the theorical size of the map (to use actual distance on the map).
 - *Preconfigured graph*: save and export graph, and maybe graph + image to give preconfigured maps, such as Europe or a country.

## Contributors

 - Etienne BOESPFLUG [etienne.boespflug@gmail.com].

## Licence

[![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](http://creativecommons.org/publicdomain/zero/1.0/)

This software has no license and is free to use.

## Disclaimer

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

