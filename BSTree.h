#ifndef BSTREE_H
#define BSTREE_H

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
        BSTree();
        bool empty();//returns true if the BST is empty
        bool insert(int value);//inserts value into the BST; returns true if the value is inserted
        bool find(int value);//returns true if value is in BST
};
#endif
