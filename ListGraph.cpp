#include "ListGraph.h"

ListGraph::ListGraph(int verticesCount) : adjLists(verticesCount) {}

ListGraph::ListGraph(const IGraph& graph) : ListGraph(graph.VerticesCount()) {
    for (int from = 0; from < VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    adjLists[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjLists.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return adjLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int from = 0; from < VerticesCount(); ++from) {
        for (int to : adjLists[from]) {
            if (to == vertex) {
                prevVertices.push_back(from);
            }
        }
    }
    return prevVertices;
}

ListGraph::~ListGraph() {
    adjLists.clear();
}

ListGraph& ListGraph::operator=(const ListGraph& l) {
    if (this == &l) {
        return *this;
    }
    adjLists = l.adjLists;
    return *this;
}