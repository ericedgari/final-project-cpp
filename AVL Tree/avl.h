#pragma once
#include <iostream>
#include <vector>
using namespace std;

class AVLTree{
    
    struct Node{
        int number;
        string name;
        Node* left;
        Node* right;
        int height;
    };
    
private:
Node* root;
vector<int> idList;
vector<string> nameList;

int getHeight(Node *node){
    if(node == NULL) return 0;
    return node -> height;
}

int getBalance(Node *node){
    return getHeight(node -> left) - getHeight(node -> right);
}

Node* createNode(int number, string name){
    Node* temp = new Node();
    temp -> number = number;
    temp -> name = name;
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> height = 1;
    return temp;
}

void updateHeight(Node *node){
    node -> height = max(getHeight(node -> left), getHeight(node -> right)) + 1;
}

Node* rightRotate(Node *node){
    Node *temp1 = node -> left;
    Node *temp2 = temp1 -> right;
    
    temp1 -> right = node;
    node -> left = temp2;
    
    updateHeight(node);
    updateHeight(temp1);
    return temp1;
}

Node* leftRotate(Node *node){
    Node *temp1 = node -> right;
    Node *temp2 = temp1 -> left;
    
    temp1 -> left = node;
    node -> right = temp2;
    
    updateHeight(node);
    updateHeight(temp1);
    return temp1;
}

Node* insertP(Node* node, int number, string name){
    if(node == NULL){
        node = createNode(number, name);
    }
    
    else if(node -> number < number){
        node -> right = insertP(node -> right, number, name);
    }
    
    else if(node -> number > number){
        node -> left = insertP(node -> left, number, name);
    }
    
    else return node;
    
    updateHeight(node);
    
    int balance = getBalance(node);

    if(balance > 1 && number < node -> left -> number){
        node = rightRotate(node);
    }
    
    else if(balance < -1 && number > node -> right -> number){
        node = leftRotate(node);
    }
    
    else if(balance > 1 && number > node -> left -> number){
        node -> left = leftRotate(node -> left);
        node = rightRotate(node);
    }
    
    else if(balance < -1 && number < node -> right -> number){
        node -> right = rightRotate(node -> right);
        node = leftRotate(node);
    }
    
    
    return node;
}

void printPreOrderP(Node* node){
    if(node != NULL){
        cout << "Name: " << node -> name  << "\t" << "Number: " << node -> number << endl;
        printPreOrderP(node -> left);
        printPreOrderP(node -> right);
    }
    else cout << "";
}

void printInOrderP(Node* node){
    if(node != NULL){
        printInOrderP(node -> left);
        cout << "Name: " << node -> name  << "\t" << "Number: " << node -> number << endl;
        nameList.push_back(node->name);
        idList.push_back(node->name);
        printInOrderP(node -> right);
    }
}

vector getNameList(){
    return nameList;
}

vector getIdlist(){
    return idList;
}

Node* getMin(Node* node){
    if(root == NULL) return root;
    else if(node -> left == NULL) return node;
    else getMin(node -> left);
}

Node* removeP(Node* node, int number){
    if(root == NULL){
        return root;
    }
    
    else if(node -> left == NULL && node -> right == NULL && node -> number != number){
        return node;
    }
    
    else if(number > node -> number){
        node -> right = removeP(node -> right, number);
    }
    
    else if(number < node -> number){
        node -> left = removeP(node -> left, number);
    }
    
    else{
        if(node -> left && node -> right){
            Node* temp = getMin(node -> right); 
            node -> number = temp -> number;
            node -> right = removeP(node -> right, temp -> number);
        }
        
        else{
            Node* temp = node -> left? node -> left : node -> right;
            if(temp == NULL){
                temp = node;
                node = NULL;
            }
            else{
                *node = *temp;
            }
            free(temp); 
        }
    }
    if(node == NULL){
        return node;
    }
    
    updateHeight(node);
    
    int balance = getBalance(node);
    
    if(balance > 1 && number < node -> left -> number){
        node = rightRotate(node);
    }
    
    else if(balance < -1 && number > node -> right -> number){
        node = leftRotate(node);
    }
    
    else if(balance > 1 && number > node -> left -> number){
        node -> left = leftRotate(node -> left);
        node = rightRotate(node);
    }
    
    else if(balance < -1 && number < node -> right -> number){
        node -> right = rightRotate(node -> right);
        node = leftRotate(node);
    }
    
    
    return node;
}

Node* searchP(Node* node, int number){
    if(node == NULL){
        return node;
    }

    if(number > node -> number){
        searchP(node -> right, number);
    }
    else if(number < node -> number){
        searchP(node -> left, number);
    }

    else{
        return node;
    }
}

public:
AVLTree(){
    root = NULL;
}

void insert(int number, string name){
    root = insertP(root, number, name);
}

void printPreOrder(){
    printPreOrderP(root);
}

void printInOrder(){
    printInOrderP(root);
}

void remove(int number){
    root = removeP(root, number);
}

string search(int number){
    if(searchP(root, number) != NULL){
        return searchP(root, number) -> name;
    }
    else return "NAN";
}

};
