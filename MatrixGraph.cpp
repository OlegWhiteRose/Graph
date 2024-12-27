#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int verticesCount) : adjMatrix(verticesCount, std::vector<bool>(verticesCount, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) : MatrixGraph(graph.VerticesCount()) {
    for (int from = 0; from < VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    adjMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return adjMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (int to = 0; to < VerticesCount(); ++to) {
        if (adjMatrix[vertex][to]) {
            nextVertices.push_back(to);
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int from = 0; from < VerticesCount(); ++from) {
        if (adjMatrix[from][vertex]) {
            prevVertices.push_back(from);
        }
    }
    return prevVertices;
}

MatrixGraph::~MatrixGraph() {
    adjMatrix.clear();
}

MatrixGraph& MatrixGraph::operator=(const MatrixGraph& m) {
    if (this == &m) {
        return *this;
    }
    adjMatrix = m.adjMatrix;
    return *this;
}