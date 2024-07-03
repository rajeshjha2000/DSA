// Problem 1: Implementing Queue Using Stack [LC-232]

class MyQueue {
public:
    stack<int> s1, s2; // Two stacks to manage the queue operations

    MyQueue() {
        // Constructor does not need to initialize anything
    }
    
    void push(int x) {
        s1.push(x); // Always push new elements onto s1
    }
    
    int pop() {
        int popValue = -1; // Initialize the value to be popped
        if (!s2.empty()) {
            // If s2 is not empty, the top of s2 is the front of the queue
            popValue = s2.top();
            s2.pop();
        } else {
            // If s2 is empty, transfer elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            // Now the top of s2 is the front of the queue
            if (!s2.empty()) {
                popValue = s2.top();
                s2.pop();
            }
        }
        return popValue; // Return the popped value
    }
    
    int peek() {
        int frontValue = -1; // Initialize the value to be peeked
        if (!s2.empty()) {
            // If s2 is not empty, the top of s2 is the front of the queue
            frontValue = s2.top();
        } else {
            // If s2 is empty, transfer elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            // Now the top of s2 is the front of the queue
            if (!s2.empty()) {
                frontValue = s2.top();
            }
        }
        return frontValue; // Return the front value
    }
    
    bool empty() {
        // The queue is empty if both s1 and s2 are empty
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
