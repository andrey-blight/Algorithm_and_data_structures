#pragma once
#include <iostream>
struct Node
{
    int v, c;
    Node *left, *right;
};
class BST
{
private:
    Node *root = NULL;
    Node *create_node(int val)
    {
        Node *el = new Node;
        el->v = val;
        el->left = NULL;
        el->right = NULL;
        el->c = 1;
        return el;
    }

public:
    void add_el(int val, Node *r = NULL, bool first = 1)
    {
        if (r == NULL)
            if (root == NULL)
            {
                root = create_node(val);
                return;
            }
            else
                r = root;
        if (val < r->v)
            if (r->left == NULL)
                r->left = create_node(val);
            else
                add_el(val, r->left);
        else if (val > r->v)
            if (r->right == NULL)
                r->right = create_node(val);
            else
                add_el(val, r->right);
        else
            ++r->c;
    }
    void print_el(Node *r = NULL, bool first = 1)
    {
        if (r == NULL && first)
            r = root;
        if (r != NULL)
        {
            print_el(r->left, 0);
            std::cout << r->v << ' ' << r->c << '\n';
            print_el(r->right, 0);
        }
    }
};