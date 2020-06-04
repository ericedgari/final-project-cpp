#include<bits/stdc++.h>
#include<Linked List.h>
#include <vector>
using namespace std;

class Hash{
    int tableSize=20;
    linked_list l[20];
    linked_list all;
    vector<string> nameList;
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
    void insertItem(string x, int id){
        l[hashFunction(x)].add_node(x,id);
        l[hashFunction(x)].sort();
        all.add_node(x,id);
        all.sort();
        }
    void results(){
        for(int i=0;i<tableSize;i++){
            if(l[i].get_head() != NULL){ 
                l[i].display(l[i].get_head());
                cout<<endl;}
            }
        }
    void delete_string(string x){
        if(l[hashFunction(x)].search(x) == -1){
            cout << "Name not found" << endl;
        }
        else{  
        l[hashFunction(x)].delete_node(x);}
    }
    int searchName(string x){
        int index = hashFunction(x);
        int result = l[index].search(x);
        return result;
    }
    vector<string> getNameList(){
        nameList = all.store(all.get_head());
        return nameList;
    }
    void vector_print(vector<string> a){
        for(int i=0; i<a.size();i++){
            cout << a.at(i)<<endl;
        }
    }
};
