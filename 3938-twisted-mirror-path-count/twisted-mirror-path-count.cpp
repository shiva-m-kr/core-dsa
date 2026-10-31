
class Solution {
public:
    int n, m;
    int left = 0;
    int up = 1;
    const int MOD = 1e9 + 7;

    vector<vector<array<int, 2>>> t;

    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom) {

        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(t[i][j][cameFrom] != -1) {
            return t[i][j][cameFrom];
        }

        if(grid[i][j] == 1) {

            if(cameFrom == left) {
                return t[i][j][cameFrom] =
                    solve(grid, i+1, j, up);
            }
            else {
                return t[i][j][cameFrom] =
                    solve(grid, i, j+1, left);
            }
        }

        int totalPathCount = 0;

        totalPathCount = (totalPathCount +
            solve(grid, i, j+1, left)) % MOD;

        totalPathCount = (totalPathCount +
            solve(grid, i+1, j, up)) % MOD;

        return t[i][j][cameFrom] = totalPathCount;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        t = vector<vector<array<int, 2>>>(
            m, vector<array<int, 2>>(n, {-1, -1})
        );

        return solve(grid, 0, 0, left);
    }
};
