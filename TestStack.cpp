#include <iostream>

#include "Stack.h"

bool areBracketsBalanced(string expr){
    Stack<char> backing;
    for(int i = 0; i < expr.length(); i++) {
        
    }
}


int main(){
    Stack<char> stack;

    sring expr = "{()[]";
    if (areBracketsBalanced(expr)){
        cout << "Balanced" << endl;
    } else{
        cout << "Not Balanced" << endl;
    }
    return 0;
}
