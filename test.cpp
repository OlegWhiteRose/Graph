#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

// функция для генерации случайных рёбер
std::vector<std::pair<int, int>> GenerateRandomEdges(int verticesCount, int edgesCount) {
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < edgesCount; ++i) {
        int from = rand() % verticesCount;
        int to = rand() % verticesCount;
        if (from != to) {
            edges.push_back({from, to});
        }
    }
    return edges;
}

// функция для заполнения графа рёбрами
void RandomFillGraphWithEdges(IGraph& graph, const std::vector<std::pair<int, int>>& edges) {
    for (const auto& edge : edges) {
        graph.AddEdge(edge.first, edge.second);
    }
}

// проверка достижимости с использованием BFS
bool CanReach(const IGraph& graph, int start, int end) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        if (vertex == end) {
            return true;
        }
        for (int neighbor : graph.GetNextVertices(vertex)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false; 
}

// сравнение графов на достижимость случайных вершин
bool CompareGraphs(const IGraph& graph1, const IGraph& graph2) {
    const int testsCount = 100;
    for (int i = 0; i < testsCount; ++i) {
        int start = rand() % graph1.VerticesCount();
        int end = rand() % graph1.VerticesCount();
        if (CanReach(graph1, start, end) != CanReach(graph2, start, end)) {
            return false; // если в одном графе достижимость вершин отличается от другого
        }
    }
    return true;
}

int main() {
    srand(time(0));

    const int verticesCount = 100;
    const int edgesCount = 150;

    // сгенерируем один список рёбер
    std::vector<std::pair<int, int>> randomEdges = GenerateRandomEdges(verticesCount, edgesCount);

    // создаём все графы с одинаковыми рёбрами
    ListGraph listGraph(verticesCount);
    RandomFillGraphWithEdges(listGraph, randomEdges);

    MatrixGraph matrixGraph(verticesCount);
    RandomFillGraphWithEdges(matrixGraph, randomEdges);

    SetGraph setGraph(verticesCount);
    RandomFillGraphWithEdges(setGraph, randomEdges);

    ArcGraph arcGraph(verticesCount);
    RandomFillGraphWithEdges(arcGraph, randomEdges);

    // проверяем, что все графы совпадают по достижимости
    if (CompareGraphs(listGraph, matrixGraph)) {
        std::cout << "MatrixGraph matches ListGraph\n";
    } else {
        std::cout << "MatrixGraph does not match ListGraph\n";
    }

    if (CompareGraphs(listGraph, setGraph)) {
        std::cout << "SetGraph matches ListGraph\n";
    } else {
        std::cout << "SetGraph does not match ListGraph\n";
    }

    if (CompareGraphs(listGraph, arcGraph)) {
        std::cout << "ArcGraph matches ListGraph\n";
    } else {
        std::cout << "ArcGraph does not match ListGraph\n";
    }

    return 0;
}
