#include <iostream>
#include <vector>
using namespace std;

int numberRunnerOneSwitch(vector<int>& sums) {
    int bestIndex = -1;
    int bestVal = -1*INT_MAX;
    for (int i=0; i<sums.size(); i++) {
        if (sums[i] > bestVal) {
            bestVal = sums[i];
            bestIndex = i;
        }
    }
    return bestIndex;
}

int numberRunner(vector<int>& nums, vector<int>& sums, int K) {
    for (int i=0; i<K; i++) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    std::cin >> N;
    std::cin >> K;
    vector<int> nums;
    vector<int> sums;
    int currentVal;
    int currentSum = 0;
    for (int i=0; i<N; i++) {
        cin >> currentVal;
        currentSum += currentVal;
        nums.push_back(currentVal);
        sums.push_back(currentSum);
    }
    std::cout << numberRunner(nums,sums,K) << '\n';
    return 0;
}