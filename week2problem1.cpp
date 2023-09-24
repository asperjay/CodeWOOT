#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long sumOfCosts(vector<int>& A, vector<int>& B, vector<long long>& C, int N, int M) {
    long long* costimates = new long long[N*N]; // costTable[i*N+j] is the cost from i to j if 0<=j<N
    for (int i=0; i<N*N; i++) {
        costimates[i] = LLONG_MAX;
    }
    for (int i=0; i<N; i++) {
        costimates[i*(N+1)] = 0;
    }
    for (int i=0; i<M; i++) {
        costimates[A[i]*N+B[i]] = C[i];
    }
    long long sum=0;
    for (int source=0; source<N; source++) {
        for (int dest=0; dest<N; dest++) {
            if (source == dest) {
                continue;
            }
            for (int helper=0; helper<N; helper++) {
                if (source == helper || dest == helper) {
                    continue;
                }
                if (costimates[source * N + helper] == LLONG_MAX || costimates[helper * N + dest] == LLONG_MAX) {
                    sum = LLONG_MAX;
                } else {
                    sum = costimates[source * N + helper] + costimates[helper * N + dest];
                }
                costimates[source * N + dest] = min(costimates[source * N + dest], sum);
            }
        }
    }
    long long result = 0;
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
    vector<int> A,B;
    vector<long long> C;
    int currentVal;
    long long currentVal2;
    for (int i=0; i<M; i++) {
        cin >> currentVal;
        A.push_back(currentVal-1);
        cin >> currentVal;
        B.push_back(currentVal-1);
        cin >> currentVal2;
        C.push_back(currentVal2);
    }
    cout << sumOfCosts(A,B,C,N,M) << '\n';
    return 0;
}