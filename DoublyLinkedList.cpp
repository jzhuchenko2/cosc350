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
