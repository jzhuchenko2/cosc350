// DoublyLinkedList class template
template <typename T>
class DoublyLinkedList {
private:
    // Node structure for the doubly linked list
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    T pop_front() {
        if (!head)
            throw std::runtime_error("List is empty");

        T frontValue = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head)
            head->prev = nullptr;
        return frontValue;
    }

    bool empty() const {
        return head == nullptr;
    }

    // Private member function to find a node at the specified position
    Node* find_node(int position) {
        if (position < 0)
            return nullptr;

        Node* current = head;
        int index = 0;
        while (current && index < position) {
            current = current->next;
            index++;
        }
        return current;
    }

    // Destructor to free memory of all nodes
    ~DoublyLinkedList() {
        while (!empty())
            pop_front();
    }
};