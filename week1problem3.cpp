#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int getBestimate(int vertexBestimate, int neighborBestimate, int distance) {
    return std::min(neighborBestimate, vertexBestimate + distance);
}

pair<int,int> largestCow(int *A, int *B, int *L, int *S, int N) {
    std::queue<int> frontiers;
    while (1) {
        ;
    }
}

int main() {
    std::string currentLine;
    int N;
    int M;
    std::cin >> N;
    std::cin >> M;
    int* A = new int[M];
    int* B = new int[M];
    int* L = new int[M];
    int* S = new int[M];
    int number;
    std::vector<int> numbers;   
    for (int i=0; i<M; i++) {
        std::cin >> A[i];
        std::cin >> B[i];
        std::cin >> L[i];
        std::cin >> S[i];
    }
    int largestCowSize;
    int minimumPathLength;
    pair<int,int> result = largestCow(A,B,L,S,N);
    std::cout << result.first << result.second << std::endl;;
    return 0;
}