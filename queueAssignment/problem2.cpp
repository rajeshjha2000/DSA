// Problem 2: Implementing Stack Using Queue [LC-225]

class MyStack {
public:
    queue<int> q; // Queue to implement stack operations

    MyStack() {
        // Constructor does not need to initialize anything specifically
    }
    
    void push(int x) {
        q.push(x); // Push the new element into the queue
        // Rotate the queue to make the last element the front of the queue
        for (int i = 0; i < q.size() - 1; i++) {
            int front = q.front(); // Get the front element
            q.pop();               // Remove the front element
            q.push(front);         // Push the front element to the back
        }
    }
    
    int pop() {
        int top = q.front(); // Get the top element (front of the queue)
        q.pop();             // Remove the top element
        return top;          // Return the top element
    }
    
    int top() {
        return q.front(); // Return the top element (front of the queue)
    }
    
    bool empty() {
        return q.empty(); // Check if the queue is empty
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
