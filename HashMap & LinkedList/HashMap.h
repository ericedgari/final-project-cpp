#include<bits/stdc++.h>
#include<Linked List.h>
using namespace std;

class Hash{
    int tableSize=20;
    linked_list l[20];
public:
    Hash(){
        }
    int hashFunction(string x){
        int sum = 0; 
        for (int i = 0; i < x.length(); i++) { 
            sum = sum + int(x[i]);
        }
        return (sum % tableSize);
    }    
    void insertItem(string x){
        l[hashFunction(x)].add_node(x);
        }
    void results(){
        for(int i=0;i<tableSize;i++){
            cout<<i+1<<". ";            l[i].display(l[i].get_head());
            cout<<endl;
            }
        }
    void delete_string(string x){
        l[hashFunction(x)].delete_node(x);}
};