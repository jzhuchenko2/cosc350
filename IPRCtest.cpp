#include <cassert>
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(){
  try{
  DoublyLinkedList<int> list;
    // Push some elements into the integer list
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    
    list.print_list(); // Print the integer list
    
    DoublyLinkedList<char> my_char_list;
    my_char_list.append('a');
    my_char_list.prepend('b');
    std::cout << "Element at position 2 in char list: " << my_char_list.get(2) << std::endl;
    
    // Remove an element from the char list
    my_char_list.set(0, 'r');
    my_char_list.push_back('z');
    my_char_list.push_front('x');
    my_char_list.remove(1);
    
    // Print both lists
    list.print_list();
    my_char_list.print_list();
    
    return 0;
    catch (const std::exception &exc)
      {
          cout << exc.what();
          return 1;
      }
}
