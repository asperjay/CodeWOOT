#include <iostream>
#include <queue>
using namespace std;

struct Cell {
    int x;
    int y;
    vector<Cell> path;
};

void getMazeSolutions(vector<vector<char>>& maze, vector<vector<Cell>> solutions, int N) {
    queue<Cell> cellsToProcess;
    cellsToProcess.push(Cell{2,2});
    Cell currrentCell;
    while (!cellsToProcess.empty()) {
        currrentCell = cellsToProcess.front();
        cellsToProcess.pop();
        if (maze[currrentCell.x-1][currrentCell.y] == '.') {
            cellsToProcess.push(Cell{currrentCell.x-1,currrentCell.y});
        }
        if (maze[currrentCell.x+1][currrentCell.y] == '.') {
            cellsToProcess.push(Cell{currrentCell.x+1,currrentCell.y});
        }
        if (maze[currrentCell.x][currrentCell.y-1] == '.') {
            cellsToProcess.push(Cell{currrentCell.x,currrentCell.y-1});
        }
        if (maze[currrentCell.x][currrentCell.y+1] == '.') {
            cellsToProcess.push(Cell{currrentCell.x,currrentCell.y+1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    std::cin >> N;
    std::cin >> K;
    vector<vector<char>> bessie;
    vector<vector<char>> essie;
    char currentVal;
    vector<char> currentSeq;
    for (int i=0; i<N; i++) {
        for (int i=0; i<N; i++) {
            cin >> currentVal;
            currentSeq.push_back(currentVal);
        }
        bessie.push_back(currentSeq);
        currentSeq.clear();
    }
    for (int i=0; i<N; i++) {
        for (int i=0; i<N; i++) {
            cin >> currentVal;
            currentSeq.push_back(currentVal);
        }
        essie.push_back(currentSeq);
        currentSeq.clear();
    }
    return 0;
}