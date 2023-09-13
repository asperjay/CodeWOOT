#include <iostream>
#include <queue>
#include <vector>
#define int long long
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

class HighestRect {
    public:
        bool operator()(rect rect1, rect rect2) {
            return rect1.h < rect2.h;
        }
};  

int calculateArea(int *L, int *R, int *H, int N) {
    int currentX=0;
    priority_queue<rect, vector<rect>, LeftmostRect> leftmostRects;
    priority_queue<rect, vector<rect>, HighestRect> activeRects;
    priority_queue<int> indices; //negatives
    rect zero;
    zero.l = 0;
    zero.r = 1000000001;
    zero.h = 0;
    activeRects.push(zero);
    indices.push(0);
    indices.push(-1000000001);
    rect currentRect;
    for (int i = 0; i < N; i++) {
        currentRect.l = L[i];
        currentRect.r = R[i];
        currentRect.h = H[i];
        leftmostRects.push(currentRect);
        indices.push(-1*(L[i]));
        indices.push(-1*(R[i]));
    }

    int currentIndex;
    int lastIndex = 0;
    int area = 0;
    int length = indices.size();
    for (int i=0; i<length; i++) {
        currentIndex = -indices.top();
        indices.pop();
        area += (currentIndex - lastIndex) * activeRects.top().h;
        while (leftmostRects.size()>0 && leftmostRects.top().l <= currentIndex) {
            activeRects.push(leftmostRects.top());
            leftmostRects.pop();
        }
        while (activeRects.size()>0&& activeRects.top().r <= currentIndex) {
            activeRects.pop();
        }
        lastIndex = currentIndex;
    }
    return area;
}

signed main() {
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
    std::cout << calculateArea(L,R,H,q) << std::endl;;
    return 0;
}