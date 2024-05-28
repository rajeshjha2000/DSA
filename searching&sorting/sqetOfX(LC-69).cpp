// class Solution {
// public:
//     int mySqrt(int x) {
//         int s =0;
//         int e = x;
//         long long int mid = s + (e-s)/2 ;
//         int ans = -1 ;
        
//         while(s <= e){
//           **iff ans is in the mid then return mid**
//         if (mid * mid == x){
//             return mid ;
//         }

//         **iff mid * mid is greater than x , then move to left **
//         else if (mid * mid > x){
//             e = mid - 1 ;
//         }
               
            **iff mid*mid is less than x then store mid in the ans and move to right

//         else {
//             ans = mid ;
//             s = mid + 1;
//         }
//         mid = s + (e - s)/2;

//         }
//         return ans ;
//             }
// };