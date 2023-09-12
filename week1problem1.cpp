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
    int child1 = 2 * parentIndex + 1;
    int child2 = child1 + 1;
    if (child1 > heap.size()) {
        return;
    }
    if (heap[parentIndex] < heap[child1]) {
        std::swap(heap[child1], heap[parentIndex]);
        sink(heap,child1);
    }
    if (child2 > heap.size()) {
        return;
    }
    if (heap[parentIndex] < heap[child2]) {
        std::swap(heap[child2], heap[parentIndex]);
        sink(heap,child2);
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
    while (std::cin >> instruction) {
        processInstruction(heap,instruction);
        printHeap(heap);
    }
    return 0;
}