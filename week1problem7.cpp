#include <iostream>
#include <queue>
using namespace std;

struct Vertex {
    int id;
    int bestimate;
};

class Bestimate {
    public:
        bool operator()(Vertex vert1, Vertex vert2) {
            return vert1.bestimate > vert2.bestimate;
        }
};

int minCost(vector<int>& D, vector<int>& A, vector<int>& B, int T) {
    priority_queue<Vertex,vector<Vertex>,Bestimate> nextVertices;
    nextVertices.push(Vertex{1,0});
    vector<vector<int>> edges; // index i of roads is a vector of fields connected to field i
    vector<int> nothing;
    vector<int> exploredVertices;
    for (int i=0; i<D.size(); i++) {
        edges.push_back(nothing);
    }
    for (int i=0; i<M; i++) {
        edges[A[i]-1].push_back(B[i]-1);
        edges[B[i]-1].push_back(A[i]-1);    
    }
    Vertex currentVertex;
    int currentNextVertex;
    Vertex newVertex;
    while (!nextVertices.empty()) {
        currentVertex = nextVertices.top();
        nextVertices.pop();
        if (currentVertex.id + 1 == D.size()) {
            return currentVertex.bestimate;
        }
        for (int i=0; i<roads[currentVertex.id].size(); i++) {
            currentNextVertex = roads[currentVertex.id][i];
            if (exploredVertices.count(currentNextVertex) == 0) {
                bestimates[currentRoad.field] = updateBestimate(bestimates[currentField.fieldNum],bestimates[currentRoad.field],currentRoad);
                newVertex.id = currentVertex.id;
                newVertex.bestimate = bestimates[currentRoad.field];
                fields.push(newField);
            }
        }
        exploredVertices.push_back(currentVertex);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,N,M;
    std::cin >> T;
    std::cin >> N;
    std::cin >> M;
    vector<int> D,A,B;
    int currentVal;
    for (int i=0; i<N; i++) {
        cin >> currentVal;
        D.push_back(currentVal);
    }
    for (int i=0; i<M; i++) {
        cin >> currentVal;
        A.push_back(currentVal);
        cin >> currentVal;
        B.push_back(currentVal);
    }
    return 0;
}