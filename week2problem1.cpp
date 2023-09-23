#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int sumOfCosts(vector<int>& A, vector<int>& B, vector<int>& C, int N, int M) {
    int* costimates = new int[N*N]; // costTable[i*N+j] is the cost from i to j if 0<=j<N
    for (int i=0; i<N*N; i++) {
        costimates[i] = INT_MAX;
    }
    for (int i=0; i<N; i++) {
        costimates[i*(N+1)] = INT_MAX;
    }
    for (int i=0; i<M; i++) {
        costimates[A[i]*N+B[i]] = C[i];
    }
    for (int source=0; source<N; source++) {
        for (int dest=0; dest<N; dest++) {
            if (source == dest) {
                continue;
            }
            for (int helper=0; helper<N; helper++) {
                if (source == helper || dest == helper) {
                    continue;
                }
                costimates[source * N + dest] = min(costimates[source * N + dest], costimates[source * N + helper] + costimates[helper * N + dest]);
            }
        }
    }
    int result;
    for (int i=0; i<N*N; i++) {
        result += costimates[i];
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    std::cin >> N;
    std::cin >> M;
    vector<int> A,B,C;
    int currentVal;
    for (int i=0; i<M; i++) {
        cin >> currentVal;
        A.push_back(currentVal);
        cin >> currentVal;
        B.push_back(currentVal);
        cin >> currentVal;
        C.push_back(currentVal);
    }
    cout << sumOfCosts(A,B,C,N,M);
    return 0;
}