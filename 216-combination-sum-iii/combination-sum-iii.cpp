class Solution {
public:
    void solve( vector<vector<int>>& ans,vector<int>&temp,int k , int n,int start){
        if(k == 0){
            if(n == 0){
                ans.push_back(temp);
                return;
            }
        }
        
        

        for(int i = start; i <= 9 ; i++){
            if(i > n) continue;
            // choose 
            temp.push_back(i);
            // exp
            solve(ans,temp,k-1,n-i,i+1);
            // backtrack
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(ans,temp,k,n,1);
        return ans;
    }
};