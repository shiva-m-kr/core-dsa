class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            int x = i+1;
            if(n%x == 0){
                ans += nums[i]*nums[i];
            }
        }
        return ans;
    }
};