// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int n = arr.size();
//         int s = 0;
//         int e = n - 1;

//         while(s < e){
//             int mid = s + (e - s)/2;

//             if(arr[mid]<arr[mid+1]){
//                 ** we are on line A **
//                 **and peak is on the right side **
//                 s = mid+1;
//             }

//             else if(arr[mid]>arr[mid+1]){
//                 **we are on line B**
//                 ** or we are on the peak **
//                 e = mid;
//             }
//         }

//         return s;
//     }
// };