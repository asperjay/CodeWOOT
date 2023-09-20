#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

vector<int> muddyRoads(vector<int>& A, vector<int>& B, int N, int M) {
    priority_queue<int, std::greater<int>> bestPath;
    stack<int> nextFields;
    nextFields.push(0);
    unordered_set<int> visited;
    vector<int> roads[N]; // index i of roads is a vector of fields connected to field i
    for (int i=0; i<M; i++) {
        roads[A[i]-1].push_back(B[i]-1);
        roads[B[i]-1].push_back(A[i]-1);    
    }
    int currentField;
    while (!nextFields.empty()) {
        if (currentField == N) {
            // compare to bestPath
        }
        currentField = nextFields.top();
        nextFields.pop();
        visited.insert(currentField);
        for (int i=0; i<roads[currentField].size(); i++) {
            if (visited.find(roads[currentField][i]) == visited.end()) {
                nextFields.push(roads[currentField][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    std::cin >> N;
    std::cin >> M;
    vector<int> A;
    vector<int> B;
    int currentVal;
    for (int i=0; i<M; i++) {
        cin >> currentVal;
        A.push_back(currentVal);
        cin >> currentVal;
        B.push_back(currentVal);
    }

    return 0;
}