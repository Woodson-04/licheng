#include<initializer_list>
#include<iostream>

/*
改进了remove（） 删除当前节点，不过目前是在“currentPos == head”时设置为currentPos为删除节点的下一个节点;在“currentPos ！= head”时设置currentPos为删除节点的上一个节点
*/

template<typename T>
class SingleLinkedList
{
    private:
        class Node
        {
            private:
                T data;
                Node *next = nullptr;
                Node(T _val){data = _val;}
                friend class SingleLinkedList<T>;
        };
        Node* head = nullptr;
        int size = 0;
        Node* currentPos = nullptr;
        void _emptyList();
        void _copy(const SingleLinkedList<T> &_l);
    public:
        T getCurrentVal() const;
        void setCurrentVal(const T &_val);
        bool isEmpty() const;
        int getSize() const;
        void emptyList();
        SingleLinkedList(){};
        ~SingleLinkedList();
        SingleLinkedList(const std::initializer_list<T> &_l);
        void printList() const;
        SingleLinkedList(const SingleLinkedList<T> &_l);
        SingleLinkedList<T> &operator = (const SingleLinkedList<T> &_l);
        void insert(const T &_val);
        bool find(const T &_val);
        void remove(); 
};

template <typename T>
bool SingleLinkedList<T>::isEmpty() const
{
    return head == nullptr;
};

template <typename T>
T SingleLinkedList <T>::getCurrentVal() const
{
    if (isEmpty())
    {     
        throw std::runtime_error("Empty current position! Can't get value!");
    };
    return currentPos->data;
};

template <typename T>
void SingleLinkedList<T>::setCurrentVal(const T &_val)
{
    if (currentPos == nullptr)
    {   
        std::cout<<"Empty current position! Can't set value!"<<"\t";
        return;
    };
    currentPos->data = _val;
};

template <typename T>
void SingleLinkedList<T>::insert(const T &_val)
{
    Node *newNode = new Node(_val);
    if (head == nullptr)
    {
        head = newNode;
        currentPos = head;
    }
    else
    {
        newNode->next = currentPos->next;
        currentPos->next = newNode;
    };
    ++size;
};

template <typename T>
void SingleLinkedList<T>::remove()
{
    if (currentPos != nullptr)
    {
        if (currentPos == head)
        {    head = head->next;
            delete currentPos;
            currentPos = head;
        }
        else
        {
            Node *preNode = head;
            while (preNode->next != currentPos)
            {
            preNode = preNode->next;
            };
            preNode->next = currentPos->next;
            delete currentPos;
            currentPos = preNode;
        };
        --size;
    };
};

template <typename T>
bool SingleLinkedList<T>:: find(const T &_val)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->data == _val)
        {
            currentPos = p;
            return true;
        }
        p = p->next;
    }
    return false;
};

template <typename T>
int SingleLinkedList<T>::getSize() const
{
    return size;
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList(const std::initializer_list<T> &_l)
{
    for (auto i = _l.begin(); i != _l.end(); ++i)
    {
        Node* newNode = new Node(*i);
        if (head == nullptr)
        {
            head = newNode;
            currentPos = head;
        }
        else
        {
            currentPos->next = newNode;
            currentPos = newNode;
        }
        ++size;
    };
};

template <typename T>
void SingleLinkedList<T>::_emptyList()
{
    Node* p = head;
    while (p != nullptr)
    {
        Node* t = p;
        p = p->next;
        delete t;
    };
};

template <typename T>
void SingleLinkedList<T>::printList() const
{
    Node* p = head;
    while (p != nullptr)
    {
        std::cout << p->data << "\t";
        p =  p->next;
    };
    std::cout << std::endl;
};

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    emptyList();
};
 
template<typename T>
void SingleLinkedList<T>::_copy(const SingleLinkedList<T> &_l)
{
    Node *p = _l.head;
    while (p != nullptr)
    {
        Node* newNode = new Node(p->data);
        if (head == nullptr)
        {
            head = newNode;
            currentPos = head;
        }
        else
        {
            currentPos->next = newNode;
            currentPos = newNode;
        };
        ++size;
        p = p->next;
    };
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &_l)
{
    _copy(_l);
};

template<typename T>
void SingleLinkedList<T>::emptyList()
{
    _emptyList();
    head = nullptr;
    currentPos = nullptr;
    size = 0;
};

template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator = (const SingleLinkedList<T> &_l)
{
    if (this == &_l)
        return *this;
    emptyList();
    _copy(_l);
    return *this;
};

