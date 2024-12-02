#include<algorithm>
#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include"Heapsort.h"
using namespace std;

bool check(const std::vector<int>& vc1, const std::vector<int>& vc2) 
{
    for (size_t i = 0; i < vc1.size(); ++i) 
    {
        if (vc1[i] != vc2[i]) return false;
    }
    return true;
}

vector<int> make_orderly_vector()
{
    // 定义向量的大小
    const size_t size = 1000000;

    // 创建并初始化一个长度为size的向量
    std::vector<int> vc(size);

    // 使用循环填充向量
    for (size_t i = 0; i < size; ++i) 
    {
        vc[i] = static_cast<int>(i); // 直接使用索引作为值，确保向量有序
    }
    return vc;
}

vector<int> make_random_vector()
{
    //创建一个有序序列
    vector<int> vc = make_orderly_vector();

    // 创建随机数生成器
    std::random_device rd;
    std::mt19937 g(rd());

    // 打乱向量
    std::shuffle(vc.begin(), vc.end(), g);

    return vc;
}

vector<int> make_reverse_vector()
{
    // 定义向量的大小
    const size_t size = 1000000;

    // 创建并初始化一个长度为size的向量
    std::vector<int> vc(size);

    // 使用循环填充向量
    for (size_t i = 0; i < size; ++i) 
    {
        vc[size-i-1] = static_cast<int>(i); // 直接使用索引作为值，确保向量有序
    }

    return vc;
}

vector<int> make_repeat_vector()
{
    // 定义向量的大小
    const size_t size = 1000000;

    // 创建随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9999); // 生成0到9999之间的随机数

    // 创建并填充向量
    std::vector<int> vc(size);
    for (size_t i = 0; i < size; ++i) 
    {
        vc[i] = dis(gen); // 随机填充每个元素
    }

    return vc;
}

int main()
{
    //创建四个所需向量
    vector<int> orderly_vc = make_orderly_vector();
    vector<int> random_vc = make_random_vector();
    vector<int> reverse_vc = make_reverse_vector();
    vector<int> repeat_vc = make_repeat_vector();
    
    // 使用自定义的Heapsort函数对向量进行排序&&开始测量时间
    vector<int> random_vc2 = random_vc;
    auto start = std::chrono::high_resolution_clock::now();
    Heapsort(random_vc);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_heapsort = end - start;
    std::cout << "Heapsort() time: " << time_heapsort.count() << " ms" << std::endl;

    // 使用标准库函数对向量进行堆排序&&开始测量时间
    std::make_heap(random_vc2.begin(), random_vc2.end());
    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(random_vc2.begin(), random_vc2.end());
    end = std::chrono::high_resolution_clock::now();
    time_heapsort = end - start;
    std::cout << "std::sort_heap() time: " << time_heapsort.count() << " ms" << std::endl;

    // 比较两个向量(相同输出True)
    std::cout << check(random_vc, random_vc2) << std::endl; 


    // 同理(orderly_vc)
    vector<int> orderly_vc2 = orderly_vc;
    start = std::chrono::high_resolution_clock::now();
    Heapsort(random_vc);
    end = std::chrono::high_resolution_clock::now();
    time_heapsort = end - start;
    std::cout << "Heapsort() time: " << time_heapsort.count() << " ms" << std::endl;
    std::make_heap(orderly_vc2.begin(), orderly_vc2.end());
    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(orderly_vc2.begin(), orderly_vc2.end());
    end = std::chrono::high_resolution_clock::now();
    time_heapsort = end - start;
    std::cout << "std::sort_heap() time: " << time_heapsort.count() << " ms" << std::endl;
    std::cout << check(orderly_vc, orderly_vc2) << std::endl; 


    // 同理(reverse_vc)
    vector<int> reverse_vc2 = reverse_vc;
    start = std::chrono::high_resolution_clock::now();
    Heapsort(reverse_vc);
    end = std::chrono::high_resolution_clock::now();
    time_heapsort = end - start;
    std::cout << "Heapsort() time: " << time_heapsort.count() << " ms" << std::endl;
    std::make_heap(reverse_vc2.begin(), reverse_vc2.end());
    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(reverse_vc2.begin(), reverse_vc2.end());
    end = std::chrono::high_resolution_clock::now();
    time_heapsort = end - start;
    std::cout << "std::sort_heap() time: " << time_heapsort.count() << " ms" << std::endl;
    std::cout << check(reverse_vc, reverse_vc2) << std::endl; 


    // 同理(repeat_vc)
    vector<int> repeat_vc2 = repeat_vc;
    start = std::chrono::high_resolution_clock::now();
    Heapsort(repeat_vc);
    end = std::chrono::high_resolution_clock::now();
    time_heapsort = end - start;
    std::cout << "Heapsort() time: " << time_heapsort.count() << " ms" << std::endl;
    std::make_heap(repeat_vc2.begin(), repeat_vc2.end());
    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(repeat_vc2.begin(), repeat_vc2.end());
    end = std::chrono::high_resolution_clock::now();
    time_heapsort = end - start;
    std::cout << "std::sort_heap() time: " << time_heapsort.count() << " ms" << std::endl;
    std::cout << check(repeat_vc, repeat_vc2) << std::endl; 

}