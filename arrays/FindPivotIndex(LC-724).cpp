// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//     vector<int> lsum(nums.size(),0);
 //   vector<int> rum(nums.size(),0);

 // calculate lsum array
 // for(int i=1; i<nums.size(); i++){
 //  lsum[i] = lsum[i-1] + nums[i-1];
 //  }

  // calculate rsum array
 // for(int i=nums.size()-2; i>=0; i--){
 //  rsum[i] = rsum[i+1] + nums[i+1];
// }
 

 // check krte hain 
// for(int i=0; i<nums.size(); i++){
//  if(lsum[i]==rsum[i]){
// return i ;
//}
// 
//         return -1;
        
//     }
// };