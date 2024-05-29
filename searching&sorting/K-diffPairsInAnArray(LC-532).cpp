// class Solution {
// public:
//  bool bs (vector<int> & nums, int start, int target){
//     int end = nums.size()-1;
//     while(start<=end){
//         int mid = start + (end - start)/2;

//         if(nums[mid]==target){
//             return true;
//         }

//         else if(nums[mid]>target){
//             end = mid + 1;
//         }

//         else{
//             start = mid + 1;
//         }
//     }
//     return false;
//  }

//    int binarySortingSol(vector<int> &nums, int k){
//     sort(nums.begin(), nums.end());
//         set<pair<int,int>> ans;

//         for(int i=0; i<nums.size(); i++){
//             bool target = bs(nums, i+1, nums[i]+k);

//             if(target){
//                 ans.insert({nums[i], nums[i]+k});
//             }

//         }
//         return ans.size();
//     }
   

//     int findPairs(vector<int>& nums, int k) {
//         return binarySortingSol(nums, k);
//     }
// };