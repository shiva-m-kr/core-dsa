class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> nums(n,0);
        for(auto vec:shifts){
            int f = vec[0];
            int s = vec[1];
            int t = vec[2];
            int x = (t == 1) ? 1 : -1;
            nums[f] += x;
            if(s+1<n){
                nums[s+1] -=x;
            }
        }
        for(int i = 0; i < n; i++){
            if(i > 0) nums[i] += nums[i-1];
            nums[i] = (nums[i] % 26 + 26) % 26;
        }
        // nums is ready 
        for(int i = 0 ; i < n ; i++){
            int x =s[i]-'a';
            x = (x + nums[i]) % 26;
            s[i] = x+'a';
        }
        return s;
    }
};