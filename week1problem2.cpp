#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct rect{
    int l;
    int r;
    int h;
};

class LeftmostRect {
    public:
        bool operator()(rect rect1, rect rect2) {
            return rect1.l > rect2.l;
        }
}; 

class RightmostRect {
    public:
        bool operator()(rect rect1, rect rect2) {
            return rect1.r > rect2.r;
        }
};  

class HighestRect {
    public:
        bool operator()(rect rect1, rect rect2) {
            return rect1.h < rect2.h;
        }
};  


template <size_t N>
int calculateArea(int (&L)[N], int (&R)[N], int (&H)[N]) {
    int currentX=0;
    priority_queue<rect, vector<rect>, LeftmostRect> leftmostRects;
    priority_queue<rect, vector<rect>, HighestRect> activeRects;
    priority_queue<int> indices; //negatives
    rect zero;
    zero.l = 0;
    zero.r = 1000000001;
    zero.h = 0;
    activeRects.push(zero);
    rect currentRect;
    for (int i = 0; i < N; i++) {
        currentRect.l = L[i];
        currentRect.r = R[i];
        currentRect.h = H[i];
        leftmostRects.push(currentRect);
        indices.push(-1*L[i]);
        indices.push(-1*R[i]);
    }

    int currentIndex;
    for (int i=0; i<indices.size(); i++) {
        currentIndex = indices.top()
        indices.pop();
        if (leftmostRects.top().l <= currentIndex) {
            activeRects.push(leftmostRects.top());
            leftmostRects.pop();
        }
    }
    return 0;   
}

int main() {
    std::string currentLine;
    int q;
    std::cin >> q;
    int* L = new int[q];
    int* R = new int[q];
    int* H = new int[q];
    int number;
    std::vector<int> numbers;   
    for (int i=0; i<q; i++) {
        std::cin >> L[i];
        std::cin >> R[i];
        std::cin >> H[i];
    }
    for (size_t i = 0; i < q; i++) {
        std::cout << L[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}