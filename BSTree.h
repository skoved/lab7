#ifndef BSTREE_H
#define BSTREE_H
#include <vector>

class BSTree{
    private:
        class Node{//container for values
            public:
                int data;
                Node* parent;
                Node* left;
                Node* right;
                Node(int data);//creates a node with all nullptrs
                Node(int data, Node* parent);//creates a node w/ a parent ptr
        };
        Node* root;
        bool insert(int value, Node* current);//the recursive part of insert
        bool find(int value, Node* current);//the recursive part of find
    public:
        BSTree();//creates a new tree with a null root
        BSTree(BSTree &tree);//creates of deep copy of tree
        ~BSTree();//removes all allocated memory for the tree
        bool empty();//returns true if the BST is empty
        bool insert(int value);//inserts value into the BST; returns true if the value is inserted
        bool find(int value);//returns true if value is in BST
        void sortedArray(std::vector<int> &list);//fills the vector with tree values in sorted order
        bool remove(int num);//removes the value from the tree
};
#endif
