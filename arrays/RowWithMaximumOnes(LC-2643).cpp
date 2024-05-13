// class //Solution {
// public:
//     vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
//         int rowSize = mat.size();
//         int colSize = mat[0].size();

//         int oneCount = INT_MIN;
//         int rowNo = 0;
//         vector<int> ans;

//         for(int row= 0; row< rowSize; row++){
//             int sum = 0;
//             for(int col=0; col<colSize; col++){
//                 if(mat[row][col]==1){
//                     sum++;
//                 }
//             }

//           if(sum>oneCount){
//             oneCount=sum;
//             rowNo=row;
//           }

//         }

//       ans.push_back(rowNo);
//       ans.push_back(oneCount);
//       return ans;

//     }
// };