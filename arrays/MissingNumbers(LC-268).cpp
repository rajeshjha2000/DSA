class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i =0; i<n; i++){
            sum = sum + nums[i];
        }

      int totalSum = (n *(n+1))/2;
      int ans = totalSum - sum;
 
     return ans;

    }
};

-----------------------------------------------
-----------------------------------------------
int xorr(vector<int>& nums){
    int ans=0;
    // 1. xorr all values of arrays
    for (int i = 0; i < nums.size(); i++)
    {
        ans=ans^nums[i];
    }
    //2. xor all ranges items [0,N]
    int n = nums.size();
    for (int i = 0; i <=n; i++)
    {
        ans = ans^i;
    }
    return ans;
}