class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int q = queries.size();
        vector<int> idx(q);
        for (int i = 0; i < q; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> cnt(n + 1, 0), res(q);
        int distinct = 0, l = 0, r = 0, m = logs.size();

        for (int id : idx) {
            int t = queries[id];
            while (r < m && logs[r][1] <= t) {
                if (cnt[logs[r][0]]++ == 0) distinct++;
                r++;
            }
            while (l < r && logs[l][1] < t - x) {
                if (--cnt[logs[l][0]] == 0) distinct--;
                l++;
            }
            res[id] = n - distinct;
        }
        return res;
    }
};