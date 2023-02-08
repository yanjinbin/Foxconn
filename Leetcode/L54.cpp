#include "../QuikTemplate.cpp"

// 螺旋打印
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &mat) {
    int up = 0, down = mat.size() - 1, left = 0, right = mat[0].size() - 1;
    vector<int> ans;
    while (up <= down && left <= right) {
      // 左->右
      for (int i = left; i <= right; i++) {
        ans.EB(mat[up][i]);
      }
      up++;

      // 上->下
      for (int i = up; i <= down; i++) {
        ans.EB(mat[i][right]);
      }
      right--;

      if (up <= down) {
        for (int i = right; i >= left; i--) {
          ans.EB(mat[down][i]);
        }
      }
      down--;
      if (left <= right) {
        for (int i = down; i >= up; i--) {
          ans.EB(mat[i][left]);
        }
      }
      left++;
    }
    return ans;
  }
};