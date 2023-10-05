#include <iostream>
#include "IntList.h"
using namespace std;
int main() {
 // Create an IntList and show it's current state
 IntList my_list_of_ints;
 cout << "After creation, my_list_of_ints has size: ";
 cout << my_list_of_ints.size() << endl;
 cout << "is_empty: " << my_list_of_ints.is_empty() << endl;
 cout << "Here is the list" << endl;
 my_list_of_ints.print_list();
 // Add some values
 cout << "I'm pushing some values on the front of the list" << endl;
 my_list_of_ints.push_front(10);
 my_list_of_ints.push_front(20);
 my_list_of_ints.push_front(30);
 my_list_of_ints.push_front(40);
 my_list_of_ints.push_front(50);
 cout << "I expect: 50, 40, 30, 20, 10" << endl;
 cout << "I'm pushing some values on the back of the list" << endl;
 my_list_of_ints.push_back(60);
 my_list_of_ints.push_back(70);
 cout << "I expect: 50, 40, 30, 20, 10, 60, 70" << endl;
 my_list_of_ints.print_list();
 cout << "Now heres to prepend 600" << endl;
 my_list_of_ints.prepend(600);
 cout << "Now heres to append 200" << endl;
 my_list_of_ints.append(200);
 cout << "Now heres to insert 45 at position 6" << endl;
 my_list_of_ints.insert(6,35);
 cout << "Here's the size: " << my_list_of_ints.size()<< endl;
 my_list_of_ints.print_list();
 cout << "Now here's the list when I remove a node from position 2" << endl;
 my_list_of_ints.remove(2);
 }
