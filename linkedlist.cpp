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
        
    void swap(Node *a, Node *b){
    	string temp = a->data;
    	a->data = b->data;
    	b->data = temp;
    	
	}
	
	void sort(){
		Node *current = get_head();
		Node *tempNode = new Node;
		string temp;
		
		if(get_head() == NULL){
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

             

    

