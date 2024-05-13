// rotate a 2D array by 90 degree

//  class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();

         // step 01 -- transpose of matrix 
//         for (int i=0; i<n ; i++){
//             for (int j = i; j< matrix[i].size();j++){
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }

       // step 02 -- reverse each element from 0 to n-1

//         for(int i = 0; i<n; i++){
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }
// };