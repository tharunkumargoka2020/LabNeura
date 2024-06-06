#include "algorithms/graph.h"
#include <vector>
#include <list>
#include <iostream>

Graph::Graph(int V){
    this->V = V;
    adjMat = std::vector<std::vector<int>>(V, std::vector<int>(V, 0));
    adjList = std::vector<std::list<int>>(V,std::list<int>());
}