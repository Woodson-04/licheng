#include <iostream>  
#include "List.h"  
  
int main()  
{  
    List<int> test;  
  
    // 测试 empty() 和 size()  
    std::cout << "初始化后列表是否为空:(应为true)" << std::boolalpha << test.empty() << std::endl;  
    std::cout << "列表大小:(应为0)" << test.size() << std::endl;  
  
    // 测试 push_back()  
    test.push_back(10);  
    test.push_back(20);  
    test.push_back(30);  
  
    std::cout << "\n调用 push_back(10, 20, 30) 后" << std::endl;  
    std::cout << "列表是否为空:(应为false)" << std::boolalpha << test.empty() << std::endl;  
    std::cout << "列表大小:(应为3)" << test.size() << std::endl;  
  
    // 测试前向迭代器  
    std::cout << "\n正向迭代遍历列表元素" << std::endl; 
    std::cout << "(应为10 20 30 )"; 
    for (auto itr = test.begin(); itr != test.end(); ++itr)  
    {  
        std::cout << *itr << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试 push_front()  
    test.push_front(5);  
    std::cout << "\n调用push_front(5)" << std::endl;  
    std::cout << "列表大小:(应为4)" << test.size() << std::endl;  
  
    // 测试后向迭代器  
    std::cout << "\n反向迭代遍历列表元素" << std::endl;
    std::cout << "(应为30 20 10 5)";  
    for (auto itr = test.end(); itr != test.begin();)  
    {  
        --itr;  
        std::cout << *itr << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试 front() 和 back()  
    std::cout << "\n第一个元素 (front):(应为5)" << test.front() << std::endl;  
    std::cout << "最后一个元素 (back):(应为30)" << test.back() << std::endl;  
  
    // 测试 pop_front()  
    test.pop_front();  
    std::cout << "\n调用pop_front()" << std::endl;  
    std::cout << "第一个元素 (front):(应为10)" << test.front() << std::endl;  
    std::cout << "列表大小:(应为3)" << test.size() << std::endl;  
  
    // 测试 pop_back()  
    test.pop_back();  
    std::cout << "\n调用pop_back()" << std::endl;  
    std::cout << "最后一个元素 (back):(应为20)" << test.back() << std::endl;  
    std::cout << "列表大小:(应为2)" << test.size() << std::endl;  
  
    // 测试 erase()  
    auto itr = test.begin();  
    ++itr; 
    test.erase(itr);  
    std::cout << "\n调用erase(第二个元素)" << std::endl;  
    std::cout << "列表大小:(应为1)" << test.size() << std::endl;  
    std::cout << "列表元素:(应为10)";  
    for (auto &x : test)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试 insert()  
    itr = test.begin();  
    ++itr;  
    test.insert(itr, 25);  
    std::cout << "\n在第二个位置插入25" << std::endl;  
    std::cout << "列表元素:(应为10 25 )";  
    for (auto &x : test)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试范围 erase()  
    test.push_back(40);  
    test.push_back(50);  
    std::cout << "\n后面添加元素40、50" << std::endl;  
    std::cout << "列表元素:(应为10 25 40 50 )";  
    for (auto &x : test)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    auto from = test.begin();  
    ++from;  
    ++from;
    auto to = test.end();  
    --to;  
    test.erase(from, to);  
    std::cout << "\n调用erase(第三个元素到最后一个元素)" << std::endl;  
    std::cout << "列表元素:(应为10 25 )";  
    for (auto &x : test)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试拷贝构造函数  
    List<int> test_copy = test;  
    std::cout << "\n使用拷贝构造函数创建新列表" << std::endl;  
    std::cout << "新列表元素:(10 25 )";  
    for (auto &x : test_copy)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试移动构造函数  
    List<int> test_move = std::move(test);  
    std::cout << "\n使用移动构造函数创建新列表后,原列表为空吗?(应为false)" << std::boolalpha << test.empty() << std::endl;  
    std::cout << "移动后的列表元素:(应为10 25 )";  
    for (auto &x : test_move)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试赋值操作符  
    test = test_copy;  
    std::cout << "\n使用赋值操作符将复制的列表赋值回原列表" << std::endl;  
    std::cout << "原列表元素:(应为10 25)";  
    for (auto &x : test)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试移动赋值操作符  
    test = std::move(test_move);  
    std::cout << "\n使用移动赋值操作符后,移动源列表为空吗(应为true)" << std::boolalpha << test_move.empty() << std::endl;  
    std::cout << "移动后的列表元素:(应为10 25 )";  
    for (auto &x : test)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试初始化列表构造函数  
    List<int> test_init = {100, 200, 300};  
    std::cout << "\n使用初始化列表创建列表" << std::endl;  
    std::cout << "列表元素:(应为100 200 300 )";  
    for (auto &x : test_init)  
    {  
        std::cout << x << " ";  
    }  
    std::cout << std::endl;  
  
    // 测试 clear()  
    test.clear();  
    std::cout << "\n调用 clear() 后，列表为空吗?(应为true)" << std::boolalpha << test.empty() << std::endl;  
  
    return 0;  
}