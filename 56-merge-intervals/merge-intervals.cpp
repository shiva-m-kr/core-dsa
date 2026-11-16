class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        if(n == 1) return intervals;

        vector<vector<int>> ans;
         int s1 = intervals[0][0];
         int e1 = intervals[0][1];

        for(int i = 1 ; i < n ; i++){
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];

            // update
            if(e1 >= s2){
                if(e1 >= e2){
                    continue;
                }else{
                    e1 = e2;
                }
            }else{// push
                ans.push_back({s1,e1});
                 s1 = intervals[i][0];
                 e1 = intervals[i][1]; 
            }
        }
        ans.push_back({s1, e1});
        return ans;      
    }
};