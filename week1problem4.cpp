#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::string currentLine;
    int T;
    std::cin >> T;
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
    Bestimate result = largestCowshortestPath(A,B,L,S,N,M);
    std::cout << result.cowSize << ' ' << result.roadLength << '\n';
    return 0;
}