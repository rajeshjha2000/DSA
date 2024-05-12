class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n);
        int index =0;

        while(index<n){
            int newIndex = (index + k) % n;
            ans[newIndex] = nums[index];

            index++;
        }
        nums = ans;
    }
};