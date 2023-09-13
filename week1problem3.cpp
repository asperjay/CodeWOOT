#include <iostream>
#include <vector>
using namespace std;

void largestCow(int *A, int *B, int *L, int *S, int N, int& largestCowSize, int& minimumPathLength) {
    return;
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
    largestCow(A,B,L,S,N,largestCowSize,minimumPathLength);
    std::cout << largestCowSize << minimumPathLength << std::endl;;
    return 0;
}