class Node {
    public:
    int value;
    int min;
    Node* next;

    Node(int value, int min, Node* next) {
        this->value = value;
        this->min = min;
        this->next = next;
    }
};

class MinStack {
public:
    Node* head;
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if(head == nullptr) {
            head = new Node(val, val, nullptr);
        }
        else {
            head = new Node(val, min(head->min, val), head);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->value;
    }
    
    int getMin() {
        return head->min;
    }
};
