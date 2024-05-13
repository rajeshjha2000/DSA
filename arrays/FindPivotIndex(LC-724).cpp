// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//        int n = nums.size();
//        int rightSum =0;
//        int leftSum = 0;

//        **step 01 = total sum as right sum**
//        for(int i=0; i<n; i++){
//         rightSum+= nums[i]; 
//        }
//         for(int i=0; i<n; i++){
//             rightSum-= nums[i];  **subtract element one by one from right sum until left sum equal to right sum**
//             if(rightSum==leftSum){
//                 return i;  **when left sum and right sum are equal then return index**
//             }
//             leftSum+=nums[i];

//         }
//         return -1;
        
//     }
// };