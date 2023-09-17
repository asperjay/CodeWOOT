#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits.h>
#include <set>
#define int long
using namespace std;

struct Bestimate{
    int roadLength;
    int cowSize;
};

struct Field{
    int fieldNum;
    Bestimate bestimate;
};

vector<Bestimate> bestimates;

struct Road{
    int field;
    int length;
    int cowSize;
};

class SmallestBestimate {
    public:
        bool operator()(Field field1, Field field2) {
            return field1.bestimate.cowSize < field2.bestimate.cowSize || 
            (field1.bestimate.cowSize == field2.bestimate.cowSize && 
            field1.bestimate.roadLength >= field2.bestimate.roadLength);
        }
};

bool isIn(int element, std::set<int> searchSpace) {
    int count = searchSpace.count(element);
    return count > 0;
}

Bestimate updateBestimate(Bestimate outsetBestimate, Bestimate destinationBestimate, Road thoroughfare) {
    Bestimate result;
    if (destinationBestimate.cowSize < std::min(outsetBestimate.cowSize, thoroughfare.cowSize)) {
        result.roadLength = outsetBestimate.roadLength + thoroughfare.length;
        result.cowSize = std::min(outsetBestimate.cowSize,thoroughfare.cowSize);
    } else if (destinationBestimate.cowSize > std::min(outsetBestimate.cowSize, thoroughfare.cowSize)) {
        result = destinationBestimate;
    } else if (destinationBestimate.roadLength < outsetBestimate.roadLength + thoroughfare.length) {
        result = destinationBestimate;
    } else {
        result.roadLength = outsetBestimate.roadLength + thoroughfare.length;
        result.cowSize = std::min(outsetBestimate.cowSize,thoroughfare.cowSize);
    }
    return result;
}

Bestimate largestCowshortestPath(int *A, int *B, int *L, int *S, int N, int M) {
    priority_queue<Field, vector<Field>, SmallestBestimate> fields;
    std::set<int> exploredFields;
    Bestimate fieldBestimate;
    fieldBestimate.roadLength=0;
    fieldBestimate.cowSize=INT_MAX;
    bestimates.push_back(fieldBestimate);
    Field field;
    field.bestimate = fieldBestimate;
    field.fieldNum = 0;
    fields.push(field);
    fieldBestimate.roadLength=INT_MAX;
    fieldBestimate.cowSize=0;
    for (int i=1; i<N; i++) {
        bestimates.push_back(fieldBestimate);
    }
    vector<Road> roads[M]; // index i of roads is a vector of roads containing field i
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
    Field currentField;
    Road currentRoad;
    Field newField;
    while (1) {
        currentField = fields.top(); // look at this field's neighbors
        fields.pop(); // no need to look back at already visited fields
        if (currentField.fieldNum == N-1) {
            break;
        }
        if (exploredFields.count(currentField.fieldNum) == 0) {
            exploredFields.insert(currentField.fieldNum);
            for (int i=0; i<roads[currentField.fieldNum].size(); i++) {
                currentRoad = roads[currentField.fieldNum][i];
                if (exploredFields.count(currentRoad.field) == 0) {
                    bestimates[currentRoad.field] = updateBestimate(bestimates[currentField.fieldNum],bestimates[currentRoad.field],currentRoad);
                    newField.fieldNum = currentRoad.field;
                    newField.bestimate = bestimates[currentRoad.field];
                    fields.push(newField);
                }
            }
        }
    }
    return bestimates[N-1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    std::cout << result.cowSize << ' ' << result.roadLength << '\n';
    return 0;
}