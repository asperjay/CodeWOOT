#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits.h>
#include <set>
using namespace std;

struct Bestimate{
    int roadLength;
    int cowSize;
};

vector<Bestimate> bestimates;

struct Road{
    int field;
    int length;
    int cowSize;
};

class SmallestBestimate {
    public:
        bool operator()(int field1, int field2) {
            return bestimates[field1].cowSize < bestimates[field2].cowSize || 
            (bestimates[field1].cowSize == bestimates[field2].cowSize && 
            bestimates[field1].roadLength >= bestimates[field2].roadLength);
        }
};

bool isIn(int element, std::set<int> searchSpace) {
    int count = searchSpace.count(element);
    return count > 0;
}

Bestimate updateBestimate(Bestimate outsetBestimate, Bestimate destinationBestimate, Road thoroughfare) {
    Bestimate result;
    result.roadLength = std::min(destinationBestimate.roadLength,
    outsetBestimate.roadLength + thoroughfare.length);
    result.cowSize = std::min(std::min(destinationBestimate.cowSize,
    outsetBestimate.cowSize), thoroughfare.cowSize);
    return result;
}

Bestimate largestCowshortestPath(int *A, int *B, int *L, int *S, int N, int M) {
    priority_queue<int, vector<int>, SmallestBestimate> fields; // field #
    std::set<int> exploredFields;
    fields.push(0);
    Bestimate fieldBestimate;
    fieldBestimate.roadLength=0;
    fieldBestimate.cowSize=INT_MAX;
    bestimates.push_back(fieldBestimate);
    fieldBestimate.roadLength=INT_MAX;
    fieldBestimate.cowSize=INT_MAX;
    for (int i=1; i<N; i++) {
        bestimates.push_back(fieldBestimate);
    }
    vector<Road> roads[M]; // index i is a vector of roads containing field i
    Road road1;
    Road road2;
    for (int i=0; i<M; i++) {
        road1.field = B[i]-1;
        road2.field = A[i]-1;
        road1.length = L[i];
        road2.length = L[i];
        road1.cowSize = S[i];
        road2.cowSize = S[i];
        roads[A[i]-1].push_back(road1);
        roads[B[i]-1].push_back(road2);
    }
    int currentField;
    Road currentRoad;
    while (1) {
        currentField = fields.top(); // look at this field's neighbors
        fields.pop(); // no need to look back at already visited fields
        if (currentField == N-1) {
            break;
        }
        if (!isIn(currentField,exploredFields)) {
            exploredFields.insert(currentField);
            vector<Road> connectedRoads = roads[currentField];
            for (int i=0; i<connectedRoads.size(); i++) {
                currentRoad = connectedRoads[i];
                if (!isIn(currentRoad.field,exploredFields)) {
                    bestimates[currentRoad.field] = updateBestimate(bestimates[currentField],bestimates[currentRoad.field],currentRoad);
                    fields.push(currentRoad.field);
                }
            }
        }
    }
    return bestimates[N-1];
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
    Bestimate result = largestCowshortestPath(A,B,L,S,N,M);
    std::cout << result.cowSize << ' ' << result.roadLength << std::endl;
    return 0;
}