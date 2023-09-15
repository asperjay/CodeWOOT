#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<int> shortestPaths;
struct Road{
    int field;
    int length;
};

int getBestimate(int fieldNum) {
    return shortestPaths[fieldNum];
}

class SmallestBestimate {
    public:
        bool operator()(int field1, int field2) {
            return getBestimate(field1) < getBestimate(field2);
        }
};

bool isIn(int element, vector<int> ) {
    for (int i=0; i<searchSpace.size(); i++) {
        if (element == searchSpace[i]) {
            return true;
        }
    }
    return false;
}

int updateBestimate(int outsetBestimate, int destinationBestimate, Road thoroughfare) {
    return std::min(destinationBestimate, outsetBestimate + thoroughfare.length);
}

pair<int,int> shortestPath(int *A, int *B, int *L, int *S, int N, int M, int cowSize) {
    priority_queue<int, vector<int>, SmallestBestimate> fields; // bestimate, field #
    vector<int> exploredFields;
    fields.push(1);
    shortestPaths.push_back(0);
    for (int i=1; i<N; i++) {
        shortestPaths.push_back(INT_MAX);
    }
    vector<Road> roads[N]; // index i is a vector of roads containing field i
    Road road1;
    Road road2;
    for (int i=0; i<M; i++) {
        if (cowSize <= S[i]) { // cow isn't fit
            road1.field = B[i];
            road2.field = A[i];
            road1.length = L[i];
            road2.length = L[i];
            roads[A[i]].push_back(road1);
            roads[B[i]].push_back(road2);
        }
    }
    while (1) {
        int currentField = fields.top(); // look at this field's neighbors
        fields.pop(); // no need to look back at already visited fields
        if (currentField == N) {
            break;
        }
        exploredFields.push_back(currentField);
        vector<Road> connectedRoads = roads[currentField];
        for (int i=0; i<connectedRoads.size(); i++) {
            Road currentRoad = connectedRoads[i];
            shortestPaths[currentRoad.field] = updateBestimate(currentField,shortestPaths[currentRoad.field],currentRoad);
            if (!isIn(currentRoad.field,exploredFields)) {}
                fields.push(currentRoad.field);
            }
        }
    }
    return getBestimate(currentField);
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
    pair<int,int> result = largestCow(A,B,L,S,N,M);
    std::cout << result.first << result.second << std::endl;
    return 0;
}