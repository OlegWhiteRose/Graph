#include "IGraph.h"
#include <unordered_set>
#include <vector>

class SetGraph : public IGraph {
public:
    explicit SetGraph(int verticesCount);
    SetGraph(const IGraph& graph);
    virtual ~SetGraph();                           

    SetGraph& operator=(const SetGraph& s);   

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> adjSets;
};