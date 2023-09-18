#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct Sequence {
    vector<char> characters;
    int distance;
};

vector<Sequence> getNextPositions(vector<char>& currentCharacters, int dist) { 
    vector<Sequence> result;
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
    for (int i=1; i<currentCharacters.size(); i++) {
        if (i == leftZeroIndex) {
            i += 2;
        } else {
            nextCharacters = currentCharacters;
            std::swap(nextCharacters[i-1],nextCharacters[leftZeroIndex]);
            std::swap(nextCharacters[i],nextCharacters[leftZeroIndex+1]);
            nextSeq.characters = nextCharacters;
            result.push_back(nextSeq);
        }
    }
    return result;
}

bool isSplit(vector<char>& currentCharacters) {
    bool reachedH = false;
    for (int i=1; i<currentCharacters.size(); i++) {
        if (reachedH) {
            if (currentCharacters[i] == 'G') {
                return false;
            }
        } else if (currentCharacters[i] == 'H') {
            reachedH = true;
        }
    }
    return true;
}

void moover(vector<char>& characters) {
    queue<Sequence> nextPositions;
    vector<Sequence> nextSubFrontier;
    Sequence currentPosition;
    unordered_set<Sequence> alreadyExplored;
    while (!nextPositions.empty()) {
        currentPosition = nextPositions.front();
        nextPositions.pop();
        if (isSplit(currentPosition.characters)) {
            std::cout << currentPosition.distance << '\n';
            return;
        }
        nextSubFrontier = getNextPositions(currentPosition.characters,currentPosition.distance+1);
        for (int i=0; i<nextSubFrontier.size(); i++) {
            if (alreadyExplored.find(nextSubFrontier[i]) != alreadyExplored.end()) {
                nextPositions.push(nextSubFrontier[i]);
            }
        }
        alreadyExplored.insert(currentPosition);
    }
    std::cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::string currentLine;
    int T;
    std::cin >> T;
    int N;
    vector<char> characters;
    for (int i=0; i<T; i++) {
        std::cin >> N;
        char currentChar;
        for (int j=0; i<N; i++) {
            std::cin >> currentChar;
            characters.push_back(currentChar);
        }
        moover(characters);
        characters.clear();
    }
    std::cout << '\n';
    return 0;
}