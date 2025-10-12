// 498. Diagonal Traverse
// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

// Example 1:


// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105

// CODE:--
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> ans(m * n);
    int d = 1;  // left-bottom -> right-top
    int row = 0;
    int col = 0;

    for (int i = 0; i < m * n; ++i) {
      ans[i] = matrix[row][col];
      row -= d;
      col += d;
      // out-of-bounds
      if (row == m)
        row = m - 1, col += 2, d = -d;
      if (col == n)
        col = n - 1, row += 2, d = -d;
      if (row < 0)
        row = 0, d = -d;
      if (col < 0)
        col = 0, d = -d;
    }

    return ans;
  }
};
