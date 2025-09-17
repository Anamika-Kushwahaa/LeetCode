// 54. SPIRAL MATRIX
// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example :

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100


// CODE:-
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row*col;
        //index intialization
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        while(count<total){
            //print starting row
            for(int idx=startingCol ; count<total && idx<=endingCol ; idx++){
                ans.push_back(matrix[startingRow][idx]);
                count++;
            }
            startingRow++;
            //printing ending column
            for(int idx=startingRow ; count<total && idx<=endingRow ; idx++){
                ans.push_back(matrix[idx][endingCol]);
                count++;
            }
            endingCol--;
            //printing ending row
            for(int idx=endingCol ; count<total && idx>=startingCol ; idx--){
                ans.push_back(matrix[endingRow][idx]);
                count++;
            }
            endingRow--;
            //printing starting column
            for(int idx=endingRow ; count<total && idx>=startingRow ; idx--){
                ans.push_back(matrix[idx][startingCol]);
                count++;
            }
            startingCol++;
        }return ans;
    }
};
