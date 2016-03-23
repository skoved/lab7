#include "BSTree.h"

BSTree::Node::Node(int data){
    this->data = data;
}

BSTree::Node::Node(int data, Node* parent){
    this->data = data;
    this->parent = parent;
}

BSTree::BSTree(){
    root = nullptr;
}

bool BSTree::empty(){
    return (root == nullptr);
}

bool BSTree::insert(int value){
    if(root == nullptr){
        root = new Node(value);
        return true;
    }
    else if(value < root->data){//check to see if the value should belong to the left branch
        if(root->left == nullptr){
            root->left = new Node(value, root);
            return true;
        }
        return insert(value, root->left);
    }
    else if(value > root->data){//check to see if the value should belong to the right branch
        if(root->right == nullptr){
            root->right = new Node(value, root);
            return true;
        }
        return insert(value, root->right);
    }
    return false;//value is already in the BST
}

bool BSTree::insert(int value, Node* current){
    if(value < current->data){//check to see if the value should belong to the left branch
        if(current->left == nullptr){
            current->left = new Node(value, current);
            return true;
        }
        return insert(value, current->left);
    }
    else if(value > current->data){//check to see if the value should belong to the right branch
        if(current->right == nullptr){
            current->right = new Node(value, current);
            return true;
        }
        return insert(value, current->right);
    }
    return false;//value is already in the BST
}

bool BSTree::find(int value){
    if(root == nullptr){
        return false;
    }
    else if(value < root->data){//check to see if the value should belong to the left branch
        if(root->left == nullptr){
            return false;
        }
        return find(value, root->left);
    }
    else if(value > root->data){//check to see if the value should belong to the right branch
        if(root->right == nullptr){
            return false;
        }
        return find(value, root->right);
    }
    return true;//value is already in the BST
}

bool BSTree::find(int value, Node* current){
    if(value < current->data){//check to see if the value should belong to the left branch
        if(current->left == nullptr){
            return false;
        }
        return find(value, current->left);
    }
    else if(value > current->data){//check to see if the value should belong to the right branch
        if(current->right == nullptr){
            return false;
        }
        return find(value, current->right);
    }
    return true;//value is already in the BST
}
