#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        int ans = climbStairs(n-1) + climbStairs(n-2);
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 5; // Example value
    std::cout << "Number of ways to climb " << n << " stairs: " << solution.climbStairs(n) << std::endl;
    return 0;
}
