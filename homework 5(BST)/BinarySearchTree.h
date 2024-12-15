#include <iostream>

class UnderflowExcepection {};

template <typename Comperable>
class BinarySearchTree
{
public:
    BinarySearchTree(): root{nullptr}{}
    BinarySearchTree(const BinarySearchTree &rhs): root{clone(rhs.root)}{}
    BinarySearchTree(BinarySearchTree &&rhs) noexcept : root{rhs.root}
    {
        rhs.root = nullptr;
    }
    ~BinarySearchTree()
    {
        makeEmpty();
    }
    const Comperable &findMin() const
    {
        if (isEmpty())
            throw UnderflowExcepection{};
        return findMin(root)->element;
    }
    const Comperable &findMax() const
    {
        if (isEmpty())
            throw UnderflowExcepection{};
        return findMax(root)->element;
    }
    bool contains(const Comperable &x) const
    {
        return contains(x, root);
    }
    bool isEmpty() const
    {
        return root == nullptr;
    }
    void printTree(std::ostream &out = std::cout) const
    {
        if (isEmpty())
        {
            out << "Empty tree" << std::endl;
        }
        else
        {
            printTree(root, out);
        }
    }
    void makeEmpty()
    {
        makeEmpty(root);
    }
    void insert(const Comperable &x)
    {
        insert(x, root);
    }
    void insert(Comperable &&x)
    {
        insert(std::move(x), root);
    }///
    void remove(const Comperable &x)
    {
        remove(x, root);
    }
    BinarySearchTree &operator=(const BinarySearchTree &rhs)
    {
        if (this != &rhs)
        {
            BinarySearchTree temp(rhs);
            std::swap(root, temp.root);
        }
        return *this;
    }
    BinarySearchTree &operator=(BinarySearchTree &&rhs) noexcept
    {
        std::swap(root, rhs.root);
        return *this;
    }

private:
    struct BinaryNode
    {
        Comperable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comperable &theElement, BinaryNode *lt, BinaryNode *rt)
            :element{theElement}, left{lt}, right{rt}{}
        BinaryNode(Comperable &&theElement, BinaryNode *lt, BinaryNode *rt)
            :element{std::move(theElement)}, left{lt}, right{rt}{}
    };
    BinaryNode *root;

    BinaryNode *findMin(BinaryNode *t)const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        if (t->left == nullptr)
        {
            return t;
        }
        return findMin(t->left);
    }
    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t != nullptr)
        {
            while (t->right != nullptr)
            {
                t = t->right;
            }
        }
        return t;
    }
    bool contains(const Comperable &x, BinaryNode *t) const
    {
        if (t == nullptr)
        {
            return false;
        }
        if (x < t->element)
        {
            return contains(x, t->left);
        }
        else if (x > t->element)
        {
            return contains(x, t->right);
        }
        else
        {
            return true;
        }
    }
    void printTree(BinaryNode *t, std::ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->element << std::endl;
            printTree(t->right, out);
        }
    }
    void makeEmpty(BinaryNode *&t)
    {
        ///这必须是一个后序遍历，为什么？
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = nullptr;
        }
    }
    void insert(const Comperable &x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{x, nullptr, nullptr};
        }
        else if (x < t->element)
        {
            insert(x, t->left);
        }
        else if (x > t->element)
        {
            insert(x, t->right);
        }
        else
        {
            ///这种情况不可省略（如果元素已存在，则不进行插入）
        }
    }
    void insert(Comperable &&x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{std::move(x), nullptr, nullptr};
        }
        else if (x < t->element)
        {
            insert(std::move(x), t->left);
        }
        else if(x > t->element)
        {
            insert(std::move(x), t->right);
        }
        else
        {

        }
    }
    BinaryNode *clone(BinaryNode *t) const
    {
        if (t== nullptr)
        {
            return nullptr;
        }
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
    }
    void remove(const Comperable &x, BinaryNode *&t) 
    {
        if (t == nullptr) 
        {
            return;
        }
        if (x < t->element)
        {
            remove(x, t->left);
        } 
        else if (x > t->element) 
        {
            remove(x, t->right);
        }
        else 
        {
            if (t->left != nullptr && t->right != nullptr)
            {
                BinaryNode *temp = detachMin(t->right);
                BinaryNode *oldNode = t;
                temp->left = oldNode->left;
                temp->right = oldNode->right;
                t = temp;
                delete oldNode;
            } 
            else 
            {
                BinaryNode *temp = t;
                t = (t->left != nullptr) ? t->left : t->right;
                delete temp;
            }
        }
    }
    BinaryNode *detachMin(BinaryNode *&t)
    {
    if (t == nullptr)
    {
        return nullptr;
    }
    else if (t->left == nullptr)
    {
        BinaryNode *temp = t;
        t = t->right;
        return temp;
    }
    return detachMin(t->left);
    }
};