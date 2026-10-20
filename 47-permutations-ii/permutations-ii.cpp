class Solution {
public:
    int n ;
    void solve(vector<int>& nums ,vector<vector<int>>& ans,vector<int>& temp,vector<int>&used){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
       for(int i = 0 ; i < n ; i++){
        if(used[i]) continue;

        if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
            continue;
        }

         // choose 
        temp.push_back(nums[i]);
        used[i] = 1;

        // explore
        solve(nums,ans,temp,used);
        // backtrack
        temp.pop_back();
        used[i] = 0;
       }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> used(n,0);
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,ans,temp,used);
        return ans;
    }
};