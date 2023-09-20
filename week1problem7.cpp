#include <iostream>
#include <queue>
using namespace std;

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