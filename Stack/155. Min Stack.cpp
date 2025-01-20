class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};
class MinStack {
    Node* head;
    Node* minHead;
public:
    MinStack() {
        head = new Node(0);
        minHead = new Node(INT_MAX);
    }
    
    void push(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;

        int minVal = min(minHead->data,val);
        Node* minTemp = new Node(minVal);
        minTemp->next = minHead;
        minHead = minTemp;
    }
    
    void pop() {
        Node* temp = head;
        head = head->next;
        delete temp;

        Node* minTemp = minHead;
        minHead = minHead->next;
        delete minTemp;
    }
    
    int top() {
        return head->data;
    }
    
    int getMin() {
        return minHead->data;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
