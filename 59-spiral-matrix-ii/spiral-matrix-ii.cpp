
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt = 1;

        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        while (left <= right && top <= bottom) {

            // Left to right
            for (int i = left; i <= right; i++) {
                ans[top][i] = cnt++;
            }
            top++;

            // Top to bottom
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = cnt++;
            }
            right--;

            // Right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = cnt++;
                }
            }
            bottom--;

            // Bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = cnt++;
                }
            }
            left++;
        }

        return ans;
    }
};
