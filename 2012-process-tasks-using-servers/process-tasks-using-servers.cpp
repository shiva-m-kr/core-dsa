class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> freeS;
        priority_queue<pair<long long, P>, vector<pair<long long, P>>, greater<pair<long long, P>>> busyS;
        for (int i = 0; i < (int)servers.size(); i += 1) {
            freeS.push({servers[i], i});
        }
        vector<int> ans(tasks.size());
        long long cur = 0;
        for (int j = 0; j < (int)tasks.size(); j += 1) {
            cur = max(cur, (long long)j);
            if (freeS.empty() && busyS.top().first > cur) {
                cur = busyS.top().first;
            }
            while (!busyS.empty() && busyS.top().first <= cur) {
                freeS.push(busyS.top().second);
                busyS.pop();
            }
            auto [w, idx] = freeS.top();
            freeS.pop();
            ans[j] = idx;
            busyS.push({cur + tasks[j], {w, idx}});
        }
        return ans;
    }
};