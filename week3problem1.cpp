#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
using namespace std;

struct Road {
    int vertex1;
    int vertex2;
    int muddiness;
    bool operator<(const Road other) const {
        // The lower the 'priority', the higher the actual priority
        return muddiness < other.muddiness;
    }
};

void muddyRoads(vector<vector<int>>& roads, vector<int>& A, vector<int>& B, int N, int M) {
    int startingVertex = 0;
    set<int> includedVertices;
    queue<Road> nextEdges;
    for (int i=0; i<roads[startingVertex].size(); i++) {
        roads[startingVertex][i]
    }
    while (true) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    std::cin >> N;
    std::cin >> M;
    vector<int> A,B;
    int currentVal;
    for (int i=0; i<M; i++) {
        cin >> currentVal;
        A.push_back(currentVal-1);
        cin >> currentVal;
        B.push_back(currentVal-1);
    }
    vector<vector<int>> roads;
    vector<int> roadsFromVertex;
    for (int i=0; i<N; i++) {
        roads.push_back(roadsFromVertex);
    }
    for (int i=0; i<M; i++) {
        roads[A[i]].push_back(B[i]);
        roads[B[i]].push_back(A[i]);
    }
    muddyRoads(roads,N,M);

    return 0;
}