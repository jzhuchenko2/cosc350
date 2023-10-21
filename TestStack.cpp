#include <iostream>

#include "Stack.h"


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
