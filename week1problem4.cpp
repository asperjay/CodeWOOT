#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <functional>
using namespace std;

struct Sequence {
    vector<char> characters;
    int distance;
    bool operator==(const Sequence& other) const {
        return characters == other.characters;
    }
};

struct SequenceHash {
    std::size_t operator()(const Sequence& Sequence) const {
        std::size_t hashCharacters = Sequence.characters.size();
        for (int elem : Sequence.characters) {
            hashCharacters ^= std::hash<int>{}(elem) + 0x9e3779b9 + (hashCharacters << 6) + (hashCharacters >> 2);
        }
        return hashCharacters;
    }
};

void getNextPositions(vector<char>& currentCharacters, int dist, vector<Sequence>& result) {
    int leftZeroIndex;
    for (int i=0; i<currentCharacters.size(); i++) {
        if (currentCharacters[i] == 'O') {
            leftZeroIndex = i;
            break;
        }
    }
    Sequence nextSeq;
    vector<char> nextCharacters;
    nextSeq.distance = dist;
    for (int i=0; i<currentCharacters.size()-1; i++) {
        if (i == leftZeroIndex - 1 || i == leftZeroIndex || i == leftZeroIndex + 1) {
            continue;
        }
        nextCharacters = currentCharacters;
        std::swap(nextCharacters[i],nextCharacters[leftZeroIndex]);
        std::swap(nextCharacters[i+1],nextCharacters[leftZeroIndex+1]);
        nextSeq.characters = nextCharacters;
        result.push_back(nextSeq);
    }
}

void printVector(vector<char>& vec) {
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i];
    }
}

bool isSplit(vector<char>& currentCharacters) {
    //printVector(currentCharacters);
    bool reachedH = false;
    for (int i=0; i<currentCharacters.size(); i++) {
        if (reachedH) {
            if (currentCharacters[i] == 'G') {
                //cout << "\n f\n";
                return false;
            }
        } else if (currentCharacters[i] == 'H') {
            reachedH = true;
        }
    }
    //cout << "\n t\n";
    return true;
}

void moover(vector<char>& characters) {
    queue<Sequence> nextPositions;
    Sequence starting;
    starting.characters = characters;
    starting.distance = 0;
    nextPositions.push(starting);
    vector<Sequence> nextSubFrontier;
    Sequence currentPosition;
    unordered_set<Sequence, SequenceHash> alreadyExplored;
    alreadyExplored.insert(starting);
    while (!nextPositions.empty()) {
        currentPosition = nextPositions.front();
        nextPositions.pop();
        if (isSplit(currentPosition.characters)) {
            std::cout << currentPosition.distance << '\n';
            return;
        }
        getNextPositions(currentPosition.characters,currentPosition.distance+1, nextSubFrontier);
        for (int i=0; i<nextSubFrontier.size(); i++) {
            if (alreadyExplored.find(nextSubFrontier[i]) == alreadyExplored.end()) {
                nextPositions.push(nextSubFrontier[i]);
                alreadyExplored.insert(nextSubFrontier[i]);
            }
        }
        nextSubFrontier.clear();
    }
    std::cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    std::cin >> T;
    int N;
    vector<char> characters;
    for (int i=0; i<T; i++) {
        std::cin >> N;
        char currentChar;
        for (int j=0; j<N; j++) {
            std::cin >> currentChar;
            characters.push_back(currentChar);
        }
        moover(characters);
        characters.clear();
    }
    return 0;
}