#pragma once
#include <vector>
#include <list>

class Graph {
    public:
        Graph(int V);
        void addEdge(int u, int v);
        void displayGraph();
    private:
        int V;
        std::vector<std::vector<int>> adjMat;
        std::vector<std::list<int>> adjList;
};