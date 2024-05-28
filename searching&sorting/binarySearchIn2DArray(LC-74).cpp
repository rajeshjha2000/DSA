// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int z = m * n ; 

//         int s = 0;
//         int e = z - 1;
//         int mid = s + ( e -s)/2 ;

//         while ( s <= e){
//             int rowIndex = mid/n ;
//             int colIndex = mid % n;
//             int currentNumber = matrix[rowIndex][colIndex];

//             if(target  == currentNumber){
//                 return true;
//             }

//             else if ( target > currentNumber){
//                 s = mid + 1;
//             }

//             else {
//                 e = mid - 1;
//             }

//             mid = s + (e - s)/2;
//         }
//         return false ;
//     }
// };