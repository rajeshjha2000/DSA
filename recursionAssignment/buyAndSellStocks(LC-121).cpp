#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    // Recursive function to find the maximum profit
    void maxProfitFinder(vector<int> &prices, int i, int &minPrice, int &maxProfit) {
        // Base case: stop recursion when index reaches the size of the array
        if (i == prices.size()) {
            return;
        }
        
        // Update minPrice if the current price is lower than the current minPrice
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        
        // Calculate today's profit if selling at the current price
        int todaysProfit = prices[i] - minPrice;
        
        // Update maxProfit if today's profit is higher than the current maxProfit
        if (todaysProfit > maxProfit) {
            maxProfit = todaysProfit;
        }

        // Recursive call to process the next index
        maxProfitFinder(prices, i + 1, minPrice, maxProfit);
    }

    // Function to find the maximum profit from a list of prices
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Initialize minPrice to a very high value
        int maxProfit = 0; // Initialize maxProfit to 0

        // Start the recursive process from the first index
        maxProfitFinder(prices, 0, minPrice, maxProfit);
        
        // Return the maximum profit found
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example prices array
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Output should be 5
    return 0;
}
