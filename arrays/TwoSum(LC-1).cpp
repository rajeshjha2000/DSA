// bool twoSum2PointerApproach(int arr[], int n, int x){
//     int l =0;
//     int h = n -1;
//     while (l< h)
//     {
//         int cSum = arr[l] + arr[h];
//         if (cSum == x)
//         {
//             return true ;
//         }
        
// else if (cSum > x)
// {
//      h--;
// }
 
//   else {
//     l++;
//   }

//     }

//     return false;
    
// }

// bool hasArrayTwoCandidates(int arr[], int n, int x){

//     sort(arr, arr+n);

//     return twoSum2PointerApproach(arr, n ,x);
// }




------------------------------------------------------------------------------

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//          step 01 = sort the array
//         sort(nums.begin(), nums.end());

//         int n = nums.size();
//         int l = 0;
//         int h = n - 1;

//         while(l < h){
//            step 02 = 
//           if(nums[l]+nums[h]==target){
//             return true;
//           }

//            step 03=> if pair sum is less than target , it means current pair is small
//            we have to move the starting index towards right to consider larger pair

//           else if(nums[l]+nums[h]<target){
//             l++;
//           }
//           else{
//             h++;
//           }
            
//           }
        
//         }
        
//     }
//     return false;
// };