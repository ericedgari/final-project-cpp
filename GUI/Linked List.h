#include <vector>
#include<bits/stdc++.h>
using namespace std;
//structure of a node with the data as a name
struct Node {
    string data;
    int id;
    
    Node* next;
    };

class linked_list{
private:
    Node *head, *tail;
public:
    linked_list(){
        head = NULL;
        tail = NULL;
        }
        
    Node* get_head(){
        return head;
    }
    //the function to add a new node with the name and id we inserted
    void add_node(string x,int id){
        Node *temp = new Node;
        temp->data = x;
        temp -> id = id;
        temp->next = NULL;
        
        if(head == NULL){
            head = temp;
            tail = temp;
            }
        else{
            tail->next = temp;
            tail = tail->next;
            }
        }
    //deletion of data using the name
    void delete_node(string x){
            Node *current = new Node;
            Node *previous = new Node;
            current = head;
            if(current->data == x){
                head = head->next;
                delete current;
                }
            else{
                while(current->data != x){
                    previous = current;
                    current = current->next;
                    }
                if(current->next == NULL){
                    tail = previous;
                    previous->next=NULL;
                    delete current;
                    }
                else{
                    previous->next=current->next;
                }
            }
    }
    //to print the linked list
    void display(Node *head){
        Node* temp = new Node;
        temp = head;
        while(temp != NULL){
            cout<<temp->data<<" " << temp -> id << " ";
            temp = temp->next;}
        }
    //get the id by searching the name
    int search(string x){
        Node* temp = new Node;
        temp = head;
        while(temp != NULL){
            if(temp -> data == x) return temp -> id;
            temp = temp -> next;
        }
        return -1;
    }
    //return vector of a name in a linked list
    vector<string> store(Node *head){
        vector<string> words;
        Node* temp = new Node;
        temp = head;
        while(temp != NULL){
            words.push_back(temp->data);
            temp = temp->next;
            }
        return words;
        }
    //search name and return it in a vector
    vector<string> searchAllName(string x){
        vector<string> search_name;
        Node* temp = new Node;
        temp = head;
        while(temp != NULL){
            if(temp -> data == x) search_name.push_back(temp->data);
            temp = temp -> next;
        }
        return search_name;
        }
    //search id by using name and return it in vector
    vector<int> searchAllID(string x){
        vector<int> search_id;
        Node* temp = new Node;
        temp = head;
        while(temp != NULL){
            if(temp -> data == x) search_id.push_back(temp->id);
            temp = temp -> next;
        }
        return search_id;
        }
    //to swap the data between 2 nodes
    void swap(Node *a, Node *b){
        string temp = a->data;
        int temp2 = a->id;
        a->data = b->data;
        b->data = temp;
        a->id = b->id;
        b->id = temp2;
    }
    // using the swap to sort the data by name
    void sort(){
        Node *current = head;
        Node *tempNode = new Node;
        string temp;
        if(head == NULL){
            return;
        }
        else{
            while(current != NULL){
                tempNode = current->next;
                while(tempNode != NULL){ 
                    if(current->data > tempNode->data){
                        swap(current,tempNode);
                    }
                        tempNode =  tempNode->next;
                }
                        current =  current->next;
            }               
        }          
    }           
};
