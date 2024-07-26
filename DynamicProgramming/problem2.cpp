// 2. Coin Change (Leetcode-322)

// ================== Exploring All Possible Ways Pattern ========================= //


// ================== Approach 1: Normal Recursion Approach ================== //
class Solution {
public:
    int solveUsingRec(vector<int>& coins, int amount){
        // Base case
        if(amount == 0){  // Agar amount 0 ho gaya to return 0
            return 0;
        }

        int mini = INT_MAX;  // Minimum coins ko track karne ke liye variable
        for(int i=0; i<coins.size(); i++){
            int coin = coins[i];

            // Agar current coin amount se chhota ya barabar hai tabhi use kar sakte hain
            if(amount - coin >= 0){
                int recKaAns = solveUsingRec(coins, amount - coin);  // Recursive call with reduced amount
                
                // Agar recursion ka answer valid hai to usko include karte hain
                if(recKaAns != INT_MAX ){
                    int ans = 1 + recKaAns;
                    mini = min(mini, ans);  // Minimum coins ka answer update karte hain
                }
            }
        }
        return mini;  // Minimum coins ka answer return karte hain
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingRec(coins, amount);
        if(ans == INT_MAX){
            // Agar answer INT_MAX hai to matlab possible nahi hai
            return -1;
        }
        else{
            // Agar answer valid hai to usko return karte hain
            return ans;
        }
    }
};

// ================== Approach 2: Top Down Approach ================== //
class Solution {
public:
    int solveUsingMemo(vector<int>& coins, int amount, vector<int>&dp){
        // Base case
        if(amount == 0){  // Agar amount 0 ho gaya to return 0
            return 0;
        }
        
        // Agar answer pehle se dp array me hai to wahi return karte hain
        if(dp[amount] != -1){
            return dp[amount];
        }

        int mini = INT_MAX;  // Minimum coins ko track karne ke liye variable
        for(int i=0; i<coins.size(); i++){
            int coin = coins[i];

            // Agar current coin amount se chhota ya barabar hai tabhi use kar sakte hain
            if(amount - coin >= 0){
                int recKaAns = solveUsingMemo(coins, amount - coin, dp);  // Recursive call with reduced amount
                
                // Agar recursion ka answer valid hai to usko include karte hain
                if(recKaAns != INT_MAX ){
                    int ans = 1 + recKaAns;
                    mini = min(mini, ans);  // Minimum coins ka answer update karte hain
                }
            }
        }
        
        dp[amount] = mini;  // DP array me answer store karte hain
        return dp[amount];  // DP array se answer return karte hain
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n+1, -1);  // DP array ko -1 se initialize karte hain

        int ans = solveUsingMemo(coins, amount, dp);  // Memoization se solution nikalte hain
        if(ans == INT_MAX){
            // Agar answer INT_MAX hai to matlab possible nahi hai
            return -1;
        }
        else{
            // Agar answer valid hai to usko return karte hain
            return ans;
        }
    }
};

// ================== Approach 3: Bottom-up ================== //
class Solution {
public:
    int solveUsingTabu(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n+1, INT_MAX);  // DP array ko INT_MAX se initialize karte hain

        dp[0] = 0;  // Initial base case ko set karte hain

        for(int value = 1; value <= amount; value++) {
            int mini = INT_MAX;  // Minimum coins ko track karne ke liye variable
            for(int i=0; i<coins.size(); i++) {
                // Agar current coin value se chhota ya barabar hai tabhi use kar sakte hain
                if(value - coins[i] >= 0) {
                    int recKaAns = dp[value - coins[i]];  // DP array se answer nikalte hain
                    
                    // Agar recursion ka answer valid hai to usko include karte hain
                    if(recKaAns != INT_MAX) {
                        int ans = 1 + recKaAns;
                        mini  = min(mini, ans);  // Minimum coins ka answer update karte hain
                    }
                }
            }
            dp[value] = mini;  // DP array me answer store karte hain
        }
        return dp[amount];  // DP array se final answer return karte hain
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingTabu(coins, amount);  // Tabulation se solution nikalte hain
        if(ans == INT_MAX){
            // Agar answer INT_MAX hai to matlab possible nahi hai
            return -1;
        }
        else{
            // Agar answer valid hai to usko return karte hain
            return ans;
        }
    }
};
