#include <iostream>
#include <stdexcept>

template <typename T> 
class DoublyLinkedList {

    private:

        class Node {
            public:
                Node(T val): value{val}, next{nullptr}, previous{nullptr} {}
                T value;
                Node* next;
                Node* previous;
        };
 
        int m_size;
        Node* m_head;
        Node* m_tail; 

 void insert_very_first_node(Node* node_to_insert) {//prepending the list
    m_head = node_to_insert;
    m_tail = node_to_insert;
    node_to_insert->next = nullptr;
    node_to_insert->previous = nullptr;
    m_size++;
}
