#pragma once
#include <iostream>
#include <vector>
using namespace std;

class AVLTree{
    
    // Structure of a leaf node
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

// Returns the height of a specified leaf node
int getHeight(Node *node){ 
    if(node == NULL) return 0;
    return node -> height;
}

// Returns the balance factor of a specified leaf node
int getBalance(Node *node){
    return getHeight(node -> left) - getHeight(node -> right);
}

// A function to create a new node
Node* createNode(int number, string name){
    Node* temp = new Node();
    temp -> number = number;
    temp -> name = name;
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> height = 1;
    return temp;
}

// A function to update the height of a node after changes
void updateHeight(Node *node){
    node -> height = max(getHeight(node -> left), getHeight(node -> right)) + 1;
}

// A function to right rotate the tree using a specified node as a pivot
Node* rightRotate(Node *node){
    Node *temp1 = node -> left;
    Node *temp2 = temp1 -> right;
    
    temp1 -> right = node;
    node -> left = temp2;
    
    // Updates the height of the nodes involved to check whether further rotations are required
    updateHeight(node); 
    updateHeight(temp1);
    return temp1;
}

// A function to left rotate the tree using a specified node as a pivot
Node* leftRotate(Node *node){
    Node *temp1 = node -> right;
    Node *temp2 = temp1 -> left;
    
    temp1 -> left = node;
    node -> right = temp2;
    
    // Updates the height of the nodes involved to check whether further rotations are required
    updateHeight(node);
    updateHeight(temp1);
    return temp1;
}

// Function to insert a new leaf to the tree
Node* insertP(Node* node, int number, string name){
    if(node == NULL){   
        node = createNode(number, name); // This checks whether the root is empty or not
    }
    
    // These 2 if statements makes the function run recursively to determine the appropriate location to allocate the new node
    else if(node -> number < number){
        node -> right = insertP(node -> right, number, name); 
    }
    
    else if(node -> number > number){
        node -> left = insertP(node -> left, number, name);
    }
    
    else return node;
    
    // Updates the height of the new node
    updateHeight(node);
    
    // Gets the balance factor of the new node
    int balance = getBalance(node);
    
    // The following 4 if statements checks whether the subtree is on a left-left case, left-right case, right-right case or right-left case
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

// Prints the tree in preorder
void printPreOrderP(Node* node){
    if(node != NULL){
        cout << "Name: " << node -> name  << "\t" << "Number: " << node -> number << endl;
        printPreOrderP(node -> left);
        printPreOrderP(node -> right);
    }
    else cout << "";
}


// Update vector for use in GUI in order of ID
void updateVectorInOrderP(Node* node){
    if(node != NULL){
        updateVectorInOrderP(node -> left);
        nameList.push_back(node->name);
        idList.push_back(node->number);
        updateVectorInOrderP(node->right);
    }
}


// Helper function to obtain minimum value of a subtree
Node* getMin(Node* node){
    if(root == NULL) return root;
    else if(node -> left == NULL) return node;
    else getMin(node -> left);
}

// Function to remove a node from the tree
Node* removeP(Node* node, int number){
    if(root == NULL){
        return root;
    }
    
    else if(node -> left == NULL && node -> right == NULL && node -> number != number){
        return node;
    }
    
    // The following 2 if function makes this function run recursively to the designated node
    else if(number > node -> number){
        node -> right = removeP(node -> right, number);
    }
    
    else if(number < node -> number){
        node -> left = removeP(node -> left, number);
    }
    
    else{
        // Case of deleted node having 2 childs
        if(node -> left && node -> right){
            Node* temp = getMin(node -> right); 
            node -> number = temp -> number;
            node -> right = removeP(node -> right, temp -> number);
        }
        
        else{
            // Case of deleted node having 1 or 0 child
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
    
    // Updates the height of the new subtree after deletion
    updateHeight(node);
    
    // Obtains balance factor
    int balance = getBalance(node);
    
     // The following 4 if statements checks whether the subtree is on a left-left case, left-right case, right-right case or right-left case
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

// Function to search for a specified id
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

// Public insert to call private function insertP()
void insert(int number, string name){
    root = insertP(root, number, name);
    nameList.clear();
    idList.clear();
    updateVectorInOrder();
}

// Public updateVector to call private function updateVectorInOrder()
void updateVector(){
    nameList.clear();
    idList.clear();
    updateVectorInOrder();
    }

// Public printPreOrder to call private function printPreOrderP()
void printPreOrder(){
    printPreOrderP(root);
}


// Public updateVectorInOrder to call private function updateVectorInOrderP()
void updateVectorInOrder(){
    updateVectorInOrderP(root);
}

// Function to return a vector containing all the names
vector<string> getNameList(){
    return nameList;
    }

// Function to return a vector containing all the ids
vector<int> getIdList(){
    return idList;
    }   

// Public remove to call private function removeP()
void remove(int number){
    root = removeP(root, number);
}

// Public search to call private function searchP()
string search(int number){
    if(searchP(root, number) != NULL){
        return searchP(root, number) -> name;
    }
    else return "NAN";
}

// Function to print out items inside vector containing ints
void printVector(vector<int> v){
    for (int i =0 ; i<v.size();i++){
        cout<<v[i]<<endl;
    }
}

// Function to print out items inside vector containing strings
void printVector(vector<string> v){
        for (int i =0 ; i<v.size();i++){
            cout<<v[i]<<endl;
        }
    }

    void printAll(){
    printVector(idList);
    printVector(nameList);
}

};
