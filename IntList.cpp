#include <iostream>
#include "IntList.h"
using namespace std;
IntList::IntList() {
 m_size = 0;
 m_head = nullptr;
 m_tail = nullptr;
}
int IntList::size() const {
 return m_size;
}
bool IntList::is_empty() const {
 return m_size == 0;
}
void IntList::print_list() const {
 if (is_empty()) {
 cout << "Empty List" << endl;
 } else {
 Node* to_print = m_head;
 while (to_print != nullptr) {
 // print the node contents
 cout << "Node: " << to_print->value << endl;
 // move on to the next node
 to_print = to_print->next;
 }
 }
}
//this assumes the linkedlist is empty
void IntList::insert_very_first_node(Node* node_to_insert) {//prepending the list
 m_head = node_to_insert;
 m_tail = node_to_insert;
 node_to_insert->next = nullptr;
 node_to_insert->previous = nullptr;
 m_size++;
}
void IntList::insert_new_head(Node* node_to_insert) {
 node_to_insert->previous = nullptr;
 node_to_insert->next = m_head;
 m_head->previous = node_to_insert;
 m_head = node_to_insert;
 m_size++;
}
void IntList::insert_new_tail(Node* node_to_insert) {
 node_to_insert->next = nullptr;
 node_to_insert->previous = m_tail;
 m_tail->next = node_to_insert;
 m_tail = node_to_insert;
 m_size++;
}
void IntList::push_front(int value) {
 // Create the node to add to the list
 Node* node_to_insert = new Node(value);
 
 if (is_empty()) {
 // if the list is empty, we are inserting the very first node
 insert_very_first_node(node_to_insert);
 } else {
 // if the list already has some elements
 insert_new_head(node_to_insert);
 }
}
void IntList::push_back(int value) {
 // Create the node to add to the list
 Node* node_to_insert = new Node(value);
 if (is_empty()) {
 // if the list is empty, we are inserting the very first node
 insert_very_first_node(node_to_insert);
 } else {
 // if the list already has some elements
 insert_new_tail(node_to_insert);
 }
}
void IntList::prepend(int value){
    Node* node_to_insert = new Node(value);
    if(m_size == 0)
    {
        insert_very_first_node(node_to_insert);
    }
    else{
        insert_new_head(node_to_insert);
    }
}
void IntList::append(int value){
    Node* node_to_insert = new Node(value);
    if(m_size == 0){
        insert_very_first_node(node_to_insert);
    }
    else{
        insert_new_tail(node_to_insert);
    }
}
void IntList::insert(int position, int value){
    if(is_empty()){
        insert_very_first_node(new Node(value));
        return;
    }
    else if(position <= 0){
        push_front(value);
        return;
    }
    else if(position >= m_size) {
        push_back(value);
        return;
    }
    else{
        Node* node_to_insert = new Node(value);
        node_to_insert->value = value;

        Node* previous_node = m_head;
        Node* next_node = m_head;

        for(int i=0; i<position; i++){
            previous_node= next_node;
            next_node = next_node->next;
        }
        insert_between_nodes(previous_node, next_node, node_to_insert);
    }
}
void IntList::insert_between_nodes(Node* previous_node, Node* next_node, Node* node_to_insert){
        if(previous_node== nullptr){
        cout << "the given previous node is cannot be null";
        return; 
        }
    node_to_insert->next = next_node;
    node_to_insert->previous = previous_node;

    previous_node->next = node_to_insert;
    next_node->previous = node_to_insert;
    m_size++;

}
int IntList::get(int position){
    if ((position <0) || (position > m_size-1)){
        throw out_of_range("get called with out of range position");
    }else{
        int current_location = 0;
        Node* current_node = m_head;

        while(current_location< position){
            current_node = current_node->next;
            current_location++;
        }
        return current_node->value;
    }
}
