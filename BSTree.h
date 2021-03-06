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
                Node(const Node &node);
        };
        Node* root;
        bool insert(int value, Node* current);//the recursive part of insert
        bool find(int value, Node* current);//the recursive part of find
        void preOrder(Node* current);//recursive helper method for copy constructor
        void postOrder(Node* current);//recursive helper method fordestructor
        void inOrder(Node* current, std::vector<int> &list);//recursive helper method for sortedArray
        Node* get(int value, Node* current);//returns the node holds the value in the tree
        void removeLeaf(Node* node);//removal for a leaf node
        void shortCircuit(Node* node);//removal for a node with one child
        void promote(Node* node);//removal for a node with two children
        Node* findMax(Node* node);//finds the max node on the left branch
    public:
        BSTree();//creates a new tree with a null root
        BSTree(const BSTree &tree);//creates of deep copy of tree
        ~BSTree();//removes all allocated memory for the tree
        bool empty();//returns true if the BST is empty
        bool insert(int value);//inserts value into the BST; returns true if the value is inserted
        bool find(int value);//returns true if value is in BST
        void sortedArray(std::vector<int> &list);//fills the vector with tree values in sorted order
        bool remove(int value);//removes the value from the tree
};
#endif
