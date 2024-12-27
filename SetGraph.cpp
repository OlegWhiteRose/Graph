#include "SetGraph.h"

SetGraph::SetGraph(int verticesCount) : adjSets(verticesCount) {}

SetGraph::SetGraph(const IGraph& graph)
    : SetGraph(graph.VerticesCount()) {
    for (int from = 0; from < VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    adjSets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjSets.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(adjSets[vertex].begin(), adjSets[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int from = 0; from < VerticesCount(); ++from) {
        if (adjSets[from].find(vertex) != adjSets[from].end()) {
            prevVertices.push_back(from);
        }
    }
    return prevVertices;
}

SetGraph::~SetGraph() {
    adjSets.clear();
}

SetGraph& SetGraph::operator=(const SetGraph& s) {
    if (this == &s) {
        return *this;
    }
    adjSets = s.adjSets;
    return *this;
}