#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    std::cin >> C;
    vector<int> D,M;
    int currentVal;
    for (int i=0; i<C; i++) {
        cin >> currentVal;
        D.push_back(currentVal);
        cin >> currentVal;
        M.push_back(currentVal);
    }
    return 0;
}