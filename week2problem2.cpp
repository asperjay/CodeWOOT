#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

void dfsReverse(vector<vector<int>>& edgesBackwards, int origin, bool* visited) {
    visited[currentNode] = true; // visited current node
    stack<int> nodesToSearch;
    nodesToSearch.push(origin);
    int currentNode;
    while (!nodesToSearch.empty()) {
        currentNode = nodesToSearch.top();
        nodesToSearch.pop();
        for (int i=0; i<edgesBackwards[currentNode].size(); i++) {
            if (!visited[edgesBackwards[currentNode][i]]) {
                nodesToSearch.push(currentNode);
            }
        }
    }
}

int trustCircles(vector<int>& A, vector<int>& B, int N, int M) {
    vector<vector<int>> edgesForwards; // if j in edges[i] then i->j
    vector<vector<int>> edgesBackwards; // if i in edges[j] then j->i
    vector<int> currentEdges;
    bool* visited = new bool[N];
    for (int i=0; i<N; i++) {
        visited[i] = false;;
    }
    for (int i=0; i<M; i++) {
        edgesForwards.push_back(currentEdges);
        edgesBackwards.push_back(currentEdges);
    }
    for (int i=0; i<M; i++) {
        edgesForwards[A[i]].push_back(B[i]);
        edgesBackwards[B[i]].push_back(A[i]);
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
    cout << trustCircless(A,B,N,M) << '\n';
    return 0;
}