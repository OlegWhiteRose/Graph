#include "IGraph.h"
#include <vector>

class ListGraph : public IGraph {
public:
    explicit ListGraph(int verticesCount);
    ListGraph(const IGraph& graph);
    virtual ~ListGraph();                       

    ListGraph& operator=(const ListGraph& l);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;    

private:
    std::vector<std::vector<int>> adjLists;
};