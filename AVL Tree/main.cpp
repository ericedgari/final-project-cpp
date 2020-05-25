#include <iostream>
#include "HashMap.h"
using namespace std;

int main(){
    
    Hash myHash;
    myHash.insertItem("Benjamin",5);
    myHash.insertItem("enjaminB",9);
    myHash.delete_string("Benjamin");
    myHash.results();

    return 0;   
}
