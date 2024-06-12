#include "algorithms/graph.h"
#include "utils/timer.h"
#include <vector>
#include <list>
#include <iostream>

Graph::Graph(int v){
    this->V = v;
    adjMat = std::vector<std::vector<int>>(V, std::vector<int>(V, 0));
    adjList = std::vector<std::list<int>>(V,std::list<int>());
}

void Graph::addEdge(int u, int v) {
    Timer timer("Graph::addEdge");
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    adjMat[u][v] = true;
    adjMat[v][u] = true;
}

void Graph::displayGraph(){
    Timer timer("Graph::displayGraph");
    std::cout << "Displaying Graph through Adjecency List:" << std::endl;
    for (int i=0; i<V; i++) {
        std::cout << i << ": ";
        for (auto u: adjList[i]){
            std::cout << " " << u;  
        }
        std::cout << std::endl;
    }
    std::cout << "Displaying Graph through Adjeceny Matrix:" << std::endl;
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            std::cout << adjMat[i][j] << " ";
        } 
        std::cout << std::endl;
    }
}

