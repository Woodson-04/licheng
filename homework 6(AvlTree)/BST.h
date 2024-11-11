#include <iostream>

class UnderflowException {};

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
            throw UnderflowException{};
        return findMin(root)->element;
    }
    const Comperable &findMax() const
    {
        if (isEmpty())
            throw UnderflowException{};
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
        insert(x, root, nullptr);
    }
    void insert(Comperable &&x)
    {
        insert(std::move(x), root, nullptr);
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

protected:
    struct BinaryNode
    {
        Comperable element;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode *parent;
        int height;

        BinaryNode(const Comperable &theElement, BinaryNode *lt, BinaryNode *rt)
            :element(theElement), left(lt), right(rt), parent(parent), height(1){}
        BinaryNode(Comperable &&theElement, BinaryNode *lt, BinaryNode *rt)
            :element(std::move(theElement)), left(lt), right(rt), parent(parent), height(1){}
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
    void insert(const Comperable &x, BinaryNode *&t, BinaryNode *parent = nullptr) 
    {
        if (t == nullptr) 
        {
            t = new BinaryNode{x, nullptr, nullptr, parent}; 
        } 
        else if (x < t->element)
        {
            insert(x, t->left, t); 
        }
        else if (x > t->element) 
        {
            insert(x, t->right, t); 
        }
        else
        {

        }
        balance(t);
    }

    void insert(const Comperable &&x, BinaryNode *&t, BinaryNode *parent = nullptr) 
    {
        if (t == nullptr) 
        {
            t = new BinaryNode{std::move(x), nullptr, nullptr, parent}; 
        } 
        else if (x < t->element)
        {
            insert(std::move(x), t->left, t); 
        }
        else if (x > t->element) 
        {
            insert(std::move(x), t->right, t); 
        }
        else
        {

        }
        balance(t);
    }

    BinaryNode *clone(BinaryNode *t, BinaryNode *parent = nullptr) const 
    {
        if (t == nullptr) 
        {
            return nullptr;
        }
        return new BinaryNode{t->element, clone(t->left, t), clone(t->right, t), parent};
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
            if (t->left != nullptr) 
            {
                t->left->parent = t;
            }
        } 
        else if (x > t->element) 
        {
            remove(x, t->right);
            if (t->right != nullptr) 
            {
                t->right->parent = t;
            }
        } 
        else 
        { 
            if (t->left == nullptr) 
            {
                BinaryNode *temp = t;
                t = t->right;
                if (t != nullptr) 
                {
                    t->parent = (temp->parent);
                }
                delete temp;
            } 
            else if (t->right == nullptr) 
            {
                BinaryNode *temp = t;
                t = t->left;
            if (t != nullptr) 
            {
                t->parent = (temp->parent);
            }
            delete temp;
            } 
            else 
            {
                BinaryNode *temp = detachMin(t->right);
                t->element = temp->element;
                delete temp;
            }
        }
        BinaryNode *current = t;
        while (current != nullptr) 
        {
            current->height = max(height(current->left), height(current->right)) + 1;
            balance(current);
            current = current->parent; 
        }
    }

    BinaryNode* detachMin(BinaryNode *&t) 
    {
        if (t->left == nullptr) 
        {
            BinaryNode *temp = t;
            t = t->right;
            if (t != nullptr) 
            {
                t->parent = temp->parent;
            }
            return temp;
        } 
        else 
        {
            BinaryNode *minNode = detachMin(t->left);
            if (t->left != nullptr) 
            {
                t->left->parent = t;
            }
            return minNode;
        }
    }

    static const int ALLOWED_IMBALANCE = 2;

    void balance( BinaryNode * & t )
    {
        if( t == nullptr )
            return;
        
        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
            if( height( t->left->left ) >= height( t->left->right ) )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
        else
        if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
            if( height( t->right->right ) >= height( t->right->left ) )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );
                
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    int height( BinaryNode *t ) const
    {
        return t == nullptr ? 0 : t->height;
    }

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    void rotateWithLeftChild(BinaryNode *&k2) 
    {
        BinaryNode *k1 = k2->left;
        k2->left = k1->right;
        if (k1->right != nullptr) 
        {
            k1->right->parent = k2; // 更新父节点指针
        }
        k1->right = k2;
        k1->parent = k2->parent; // 更新父节点指针
        k2->parent = k1;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(BinaryNode *&k1) 
    {
        BinaryNode *k2 = k1->right;
        k1->right = k2->left;
        if (k2->left != nullptr) 
        {
            k2->left->parent = k1; // 更新父节点指针
        }
        k2->left = k1;
        k2->parent = k1->parent; // 更新父节点指针
        k1->parent = k2;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
    }

    void doubleWithLeftChild(BinaryNode *&k3) 
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void doubleWithRightChild(BinaryNode *&k1) 
    {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }


};