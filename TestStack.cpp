#include <iostream>

#include "Stack.h"

bool areBracketsBalanced(string expr){
    Stack<char> backing;
    for(int i = 0; i < expr.length(); i++) {
        if (backing.is_empty()) {
                    
            // If the stack is empty 
            // just push the current bracket
            backing.push(expr[i]);
        } else if ((backing.peak() == '(' && expr[i] == ')') ||
                   (backing.peak() == '{' && expr[i] == '}')|| 
                   (backing.peak() == '[' && expr[i] == ']')) {
                
                    backing.pop();
        } else {
            backing.push(expr[i]);
        }
    }
    if (backing.is_empty()) {
                
        // If stack is empty return true
        return true;
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
