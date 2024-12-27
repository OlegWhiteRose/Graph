#include "IGraph.h"
#include <vector>
#include <utility>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int verticesCount);
    ArcGraph(const IGraph& graph);
    virtual ~ArcGraph();                       

    ArcGraph& operator=(const ArcGraph& a);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int verticesCount;
    std::vector<std::pair<int, int>> edges;
};