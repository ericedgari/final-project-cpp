#include<bits/stdc++.h>
using namespace std;

struct Node {
    string data;
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
    
    void add_node(string x){
        Node *temp = new Node;
        temp->data = x;
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
    void display(Node *head){
        while(head != NULL){
            cout<<head->data<<" ";
            head = head->next;}
        }
             
    };
    
    
    
    
