#include <iostream>
#include <vector>
using namespace std;
void swim(std::vector<int>& heap, int childIndex) {
    int parentIndex = (childIndex - 1) / 2;

    while (childIndex > 0 && heap[parentIndex] > heap[childIndex]) {
        std::swap(heap[childIndex], heap[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}
int main() {
    std::cout << "Hello World!" << std::endl;
    std::vector<int> heap = {4,1,2};
    heap.push_back(3);
    for (size_t i = 0; i < heap.size(); i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
    swim(heap,3);
    for (size_t i = 0; i < heap.size(); i++) {
        std::cout << heap[i] << " ";
    }
    return 0;
}