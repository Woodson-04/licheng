#include<iostream>
#include<initializer_list>

#define NTL -1

typedef double t_ele;

class ArrayList
{
private:
    int size = 0;
    t_ele *data = nullptr;
public:
    ArrayList(){};
    ArrayList(std::initializer_list<t_ele> _l)
    {
        size = _l.size();
        data = new t_ele [size];
        int i = 0;
        for (t_ele e : _l)
        {
            data[i] = e;
            i++;
        }
    };

    void printList()
    {
        std::cout << "Values:" << std::endl;
        for (int i = 0;i<size;i++)
            std::cout << data[i] << "\t";
        std::cout << std::endl;
    };

    void makeEmpty()
    {
        size = 0;
        if (data != nullptr)
            delete [] data;
    };

    int find(t_ele _v)
    {
        for (int i = 0;i < size; i++)
            if (_v == data[i])
               return i;
        return NIL;
    };

    void insert(t_ele _v,int _p);

    void push_ahead(t_ele _v)
    {
        if (size ==0)
        {
            data = new t_ele;
            *data = _v;
            size ++;
            return;
        }
        t_ele *new_data = new t_ele[size + 1];
        *new_data = _v;
        for (int i = 1; i < size; i++)
            new_data[i] = data[i-1];
        delete [] data;
        data = new_data;
        size ++;
    };

    void remove(t_ele _v)
    {
        int idx = find(_v);
        if (idx == NIL)
            return;
        t_ele *new_data = new t_ele [size - 1];
        for (int i = 0; i < idx; i++)
            new_data[i] = data[i];
        for (int i = idx + 1; i < size; i++)
            new_data[i - 1] = data[i];
        delete data;
        data = new_data;
    };

    ~ArrayList()
    {
        makeEmpty();
    };
};

int main()
{
    ArrayList A {1, 2, 3, 4, 5};
    A.push_ahead(3.1);
    A.push_ahead(4.1);
    A.push_ahead(5.1);

    A.printList();
    return 0;
}
