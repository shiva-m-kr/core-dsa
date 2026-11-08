class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        map<int, int> row;
        map<int, int> column;
        vector<pair<int, int>> positions;

        for(int i = 0; i < grid.size(); i++) {
            row[i] = 0;
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    column[j]++;
                    positions.push_back({i, j});
                }
            }
        }

        int n = 0;

        for(auto p : positions) {
            if(row[p.first] > 1 || column[p.second] > 1) {
                n++;
            }
        }

        return n;
    }
};