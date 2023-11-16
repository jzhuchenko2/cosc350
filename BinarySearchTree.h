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
BinarySearchTreeNode* root;
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const Comparable &x)
    {
        if (root == nullptr)
        {
            root = new BinarySearchTreeNode(x);
        }
        else
        {
            root->insert(x);
        }
    }

    void inorder_print() const
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty." << std::endl;
        }
        else
        {
            inorderPrintHelper(root);
            std::cout << std::endl;
            //std::cout << "whats life" << std::endl;
        }
    }

    void preorder_print() const
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty." << std::endl;
        }
        else
        {
            preorderPrintHelper(root);
            std::cout << std::endl;
        }
    }

    void postorder_print() const
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty." << std::endl;
        }
        else
        {
            postorderPrintHelper(root);
            std::cout << std::endl;
        }
    }
private:
    // Helper functions go here...

    void inorderPrintHelper(const BinarySearchTreeNode *node) const
    {
        if (node != nullptr)
        {
            inorderPrintHelper(node->left);
            std::cout << node->value << " ";
            inorderPrintHelper(node->right);
        }
    }

    void preorderPrintHelper(const BinarySearchTreeNode *node) const
    {
        if (node != nullptr)
        {
            std::cout << node->value << " ";
            preorderPrintHelper(node->left);
            preorderPrintHelper(node->right);
        }
    }

    void postorderPrintHelper(const BinarySearchTreeNode *node) const
    {
        if (node != nullptr)
        {
            postorderPrintHelper(node->left);
            postorderPrintHelper(node->right);
            std::cout << node->value << " ";
        }
    }
};

/*
#pragma once

template <typename Comparable>
class BinarySearchTreeNode {
public:
    Comparable m_value;
    BinarySearchTreeNode* m_left;
    BinarySearchTreeNode* m_right;
    int m_height;

    BinarySearchTreeNode(const Comparable& the_value, BinarySearchTreeNode* lt = nullptr, BinarySearchTreeNode* rt = nullptr)
        : m_value(the_value), m_left(lt), m_right(rt), m_height(0) {}
};
*/
