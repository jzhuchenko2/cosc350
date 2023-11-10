#pragme once
#include <iostream>
#include <stdexcept>

template <typename Comparable>
class BinarySearchTree
{
private:
    class BinarySearchTreeNode
    {
    public:
        Comparable value;
        BinarySearchTreeNode *left;
        BinarySearchTreeNode *right;

        BinarySearchTreeNode(const Comparable &val, BinarySearchTreeNode *l = nullptr, BinarySearchTreeNode *r = nullptr)
            : value(val), left(l), right(r) {}

        void insert(const Comparable &x)
        {
            if (x < value)
            {
                if (left == nullptr)
                {
                    left = new BinarySearchTreeNode(x);
                }
                else
                {
                    left->insert(x);
                }
            }
            else if (x > value)
            {
                if (right == nullptr)
                {
                    right = new BinarySearchTreeNode(x);
                }
                else
                {
                    right->insert(x);
                }
            }
            else
            {
                throw std::logic_error("Duplicate value not allowed");
            }
        }
    };
