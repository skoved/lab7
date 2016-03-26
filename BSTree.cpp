#include "BSTree.h"
#include <vector>
using namespace std;

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

BSTree::BSTree(const BSTree &tree){
    if(tree.root != nullptr){//checks if it is passed an empty tree
        this->insert(tree.root->data);
        preOrder(tree.root->left);
        preOrder(tree.root->right);
    }
    else
        this->root = nullptr;
}

void BSTree::preOrder(Node* current){
    if(value != nullptr){
        insert(current->data);
        preOrder(current->left);
        preOrder(current->right);
    }
}

BSTree::~BSTree(){
    postOrder(root);
}

void BSTree::postOrder(Node* current){
    if(current != nullptr){
        postOrder(current->left);
        postOrder(current->right);
        removeLeaf(current);
    }
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

void BSTree::sortedArray(vector<int> &list){
    if(root != nullptr){
        inOrder(root->left);
        list.push_back(root->data);
        inOrder(root->right);
    }
}

void BSTree::inOrder(Node* current){
    if(current != nullptr){
        inOrder(current->left);
        list.push_back(current->data);
        inOrder(current->right);
    }
}

bool BSTree::remove(int value){
    Node* node = find(value, root)
    if(node == nullptr)
        return false;
    if(node->left == nullptr && node->right == nullptr)
        removeLeaf(node);
    else if(node->left == nullptr || node->right == nullptr)
        shortCircuit(node);
    else
        promote(node);
    return true;
}

Node* BSTree::find(int value, Node* current){
    if(value < current->data){//check to see if the value should belong to the left branch
        if(current->left == nullptr){
            return nullptr;
        }
        return find(value, current->left);
    }
    else if(value > current->data){//check to see if the value should belong to the right branch
        if(current->right == nullptr){
            return nullptr;
        }
        return find(value, current->right);
    }
    return current;
}

void BSTree::removeLeaf(Node* node){
    if(root == node)
        root == nullptr;
    else if(node->parent->right == node)
        node->parent->right = nullptr;
    else 
        node->parent->left = nullptr;
    delete node;
}

void BSTree::shortCircuit(Node* node){
    if(node == root){
        if(node->left != nullptr)
            root = node->left;
        else
            root = node->right;
        delete node;
    }
    else if(node->parent->right == node){
        if(node->right != nullptr)
            node->parent->right = node->right;
        else
            node->parent->right = node->left;
    }
    else{
        if(node->right != nullptr)
            node->parent->left = node->right;
        else
            node->parent->left = node->left;
    }
    delete node;
}

void BSTree::promote(Node* node){
    Node* temp = findMax(node);
    node->data = temp->data;
    if(temp->left == nullptr || temp->right == nullptr){
        shortCircuit(temp);
    else
        removeLeaf(temp);
}

Node* BSTree::findMax(Node* node){
    node = node->left;
    while(node->right != nullptr)
        node = node->right;
    return node;
}
