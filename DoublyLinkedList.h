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
 void insert_new_head(Node* node_to_insert){
 node_to_insert->previous = nullptr;
 node_to_insert->next = m_head;
 m_head->previous = node_to_insert;
 m_head = node_to_insert;
 m_size++;
}
 void insert_new_tail(Node* node_to_insert){
 node_to_insert->next = nullptr;
 node_to_insert->previous = m_tail;
 m_tail->next = node_to_insert;
 m_tail = node_to_insert;
 m_size++;
}
 void insert_between_nodes(Node* previous_node, Node* next_node, Node* node_to_insert){
    node_to_insert->next = next_node;
    node_to_insert->previous = previous_node;

    previous_node->next = node_to_insert;
    next_node->previous = node_to_insert;
    m_size++;
}
 T remove_only_node() {
    Node* node_to_free = m_head;
    int value_to_return = node_to_free->value;

    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;

    delete node_to_free;
    return value_to_return;
}
 T remove_head(){
    if(size() < 2) {
        throw std::out_of_range("remove_head should be on list with size >= 2");
    }
    Node* node_to_free = m_head;
    int value_to_return = node_to_free->value;

    m_head = m_head->next;
    m_head->previous = nullptr;
    m_size--;

    delete node_to_free;
    return value_to_return;
}
 T remove_tail(){
    if(size() < 2) {
        throw std::out_of_range("remove_tail should be on list with size >= 2");
    }
    Node* node_to_free = m_tail;
    int value_to_return = node_to_free->value;

    m_tail = m_tail->previous;
    m_tail->next = nullptr;
    m_size--;

    delete node_to_free;
    return value_to_return;
}
 T remove_node(Node* node_to_remove){
    int value_to_return = node_to_remove->value;
    
    Node *previous_node = node_to_remove->previous;
    Node *next_node = node_to_remove->next;
    
    previous_node->next = next_node;
    next_node->previous = previous_node;

    delete node_to_remove;
    
    m_size--;
    return value_to_return;
}

    public:
DoublyLinkedList():
    m_size{0}, m_head{nullptr}, m_tail{nullptr}{}

//( int data, Node *prev = nullptr, Node *next = nullptr)
       // : data( data ), prev( prev ), next( next )  {
    

T size() const{
    return m_size;
}
bool is_empty() const{
    return size() == 0;
}
void print_list() const {
 if (is_empty()) {
 std::cout << "Empty List" << std::endl;
 } else {
 Node* to_print = m_head;
 while (to_print != nullptr) {
 // print the node contents
 std::cout << "Node: " << to_print->value << std::endl;
 // move on to the next node
 to_print = to_print->next;
 }
 }
}
void push_front(int value) {
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
void push_back(int value) {
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
void prepend(int value){
    Node* node_to_insert = new Node(value);
    if(m_size == 0)
    {
        insert_very_first_node(node_to_insert);
    }
    else{
        insert_new_head(node_to_insert);
    }
}
void append(int value){
    Node* node_to_insert = new Node(value);
    if(m_size == 0){
        insert_very_first_node(node_to_insert);
    }
    else{
        insert_new_tail(node_to_insert);
    }
}
void insert(int position, int value){
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

 T pop_head(){
    if (size() <=0) {
        throw std::out_of_range("pop_head called on empty list");
    } else if (size() == 1) {
        return remove_only_node();
    } else {
        return remove_head();
    }
}
 T pop_tail(){
    if (size() <=0) {
       throw std::out_of_range("pop_tail called on empty list");
    } else if (size() == 1) {
        return remove_only_node();
    } else {
        return remove_tail();
    }
 }
 T get(int position){
    if ((position <0) || (position > m_size-1)){
        throw std::out_of_range("get called with out of range position");
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
 T remove(int position) {
    if((position < 0) || (position >= size())){
       throw std::out_of_range("remove_tail should be on list with size >= 0");
    }
    else if(position == 0){
        pop_head();
    }
    else if(position == size()-1){
        pop_tail();
    }
    else if(size() == 1){
        remove_only_node();
    }
    else{
        Node* node_to_remove = m_head;

        for(int i=0; i<position; i++){
            node_to_remove = node_to_remove->next;
        }
        return remove_node(node_to_remove);
    }
}
 
 T set(int position, int value){
    if ((position <0) || (position > size())){
        throw std::out_of_range("get called with out of range position");
    }else{

        Node* current = m_head;

        int i=0;
        while(current != nullptr && i <position){
            current = current->next;
            ++i;
        }
        if(current == nullptr){
            return -1;
        }
        int prev_val = current->value;
        current->value = value;
        return prev_val;}
}};