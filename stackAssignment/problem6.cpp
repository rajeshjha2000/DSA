// Problem 6 : Online Stock Span [LC-901]

class StockSpanner {
public:
    // Stack to store pairs of (price, span)
    stack<pair<int, int>> st;

    // Constructor
    StockSpanner() {
        // Initialize the stack (though it's not strictly necessary)
    }
    
    // Function to calculate the stock span for the given price
    int next(int price) {
        int span = 1; // Initial span for the current price
        
        // While stack is not empty and the price at the top of the stack is less than or equal to the current price
        while(!st.empty() && st.top().first <= price) {
            // Add the span of the top element to the current span
            span += st.top().second;
            // Pop the top element as it's included in the span
            st.pop();
        }
        
        // Push the current price and its calculated span onto the stack
        st.push({price, span});
        
        // Return the calculated span for the current price
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
