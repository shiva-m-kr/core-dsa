class Solution {
public:
    void solve(vector<int>& candidates, int target,int idx ,  vector<vector<int>>& ans,vector<int>& temp ){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = idx ; i < candidates.size() ; i++){
            if(candidates[i] > target){
                continue;
            }
            // choose 
            temp.push_back(candidates[i]);
            // explore 
            solve(candidates,target-candidates[i],i,ans,temp);
            // backtrack
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,0,ans,temp);
        return ans;
    }
};