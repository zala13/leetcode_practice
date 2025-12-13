/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30203
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int m = matrix.size(), n = matrix[0].size();
        int left_bound = 0, right_bound = n - 1, up_bound = 0, down_bound = m - 1;
        while (left_bound <= right_bound && up_bound <= down_bound) {
            for (int i = left_bound; i <= right_bound && up_bound <= down_bound; i++) {
                res.push_back(matrix[up_bound][i]);
            }
            up_bound++;
            for (int j = up_bound; j <= down_bound && left_bound <= right_bound; j++) {
                res.push_back(matrix[j][right_bound]);
            }
            right_bound--;
            for (int p = right_bound; p >= left_bound && up_bound <= down_bound; p--) {
                res.push_back(matrix[down_bound][p]);
            }
            down_bound--;
            for (int q = down_bound; q >= up_bound && left_bound <= right_bound; q--) {
                res.push_back(matrix[q][left_bound]);
            }
            left_bound++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

