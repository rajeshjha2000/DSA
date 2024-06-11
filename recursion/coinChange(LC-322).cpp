class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        // base case
        if (amount == 0) {
            return 0;
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            // current coin ko tbhi use krenge jb uski value <= amount hogi
            if (coin <= amount) {
                int recAns = solve(coins, amount - coin);
                if (recAns != INT_MAX) {
                    mini = min(mini, 1 + recAns);
                }
            }
        }
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans; // return -1 if no valid solution found
    }
};