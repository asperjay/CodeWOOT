#include <iostream>
#include <vector>
using namespace std;
void swim(std::vector<int>& heap, int childIndex) {
    int parentIndex = (childIndex - 1) / 2;

    while (childIndex > 0 && heap[parentIndex] < heap[childIndex]) {
        std::swap(heap[childIndex], heap[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}
void sink(std::vector<int>& heap, int parentIndex = 0) {
    int childIndex = 2 * parentIndex + 1;
    if (heap[2 * parentIndex + 1] < heap[2 * parentIndex + 2]) {
        childIndex = 2 * parentIndex + 2;
    }

    while (childIndex < heap.size() && heap[parentIndex] < heap[childIndex]) {
        std::swap(heap[childIndex], heap[parentIndex]);
        parentIndex = childIndex;
        childIndex = 2 * parentIndex + 1;
        if (heap[2 * parentIndex + 1] < heap[2 * parentIndex + 2]) {
            childIndex = 2 * parentIndex + 2;
        }
    }
}
void processInstruction(std::vector<int>& heap, int instruction) {
    if (instruction == 0) {
        int last = heap.back();
        heap.pop_back();    
        heap[0] = last;
        sink(heap);
    } else {
        heap.push_back(instruction);
        swim(heap,heap.size()-1);
    }
}
void printHeap(std::vector<int>& heap) {
    for (size_t i = 0; i < heap.size(); i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> heap;
    int instruction;
    int q;
    std::cin >> q;
    for (int i=0; i<q; i++) {
        std::cin >> instruction;
        processInstruction(heap,instruction);
        printHeap(heap);
    }
    return 0;
}