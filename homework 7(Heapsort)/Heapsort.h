#include<algorithm>
#include<iostream>
#include<vector>
#include<random>
#include<chrono>
using namespace std;

// 手动调整堆，使其满足最大堆性质
void adjust_heap(std::vector<int>& vec, int i, int heap_size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && vec[left] > vec[largest]) {
        largest = left;
    }

    if (right < heap_size && vec[right] > vec[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(vec[i], vec[largest]);
        adjust_heap(vec, largest, heap_size);
    }
}

// 手动建堆
void build_heap(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        adjust_heap(vec, i, n);
    }
}

// 堆排序
void Heapsort(std::vector<int>& vec) {
    build_heap(vec); // 手动建堆

    for (int i = vec.size() - 1; i > 0; --i) {
        std::swap(vec[0], vec[i]); // 交换堆顶和最后一个元素
        adjust_heap(vec, 0, i); // 重新调整堆
    }
}