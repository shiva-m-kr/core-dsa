class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int a = 1 ;
        int b = 1;
        int ans = 1;
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i]<nums[i+1]){
                a++;
            }else{
                a = 1;
            }
            if(nums[i] > nums[i+1]){
                b++;
            }else{
                b =1;
            }
            ans = max({ans,a,b});
        }
        return ans;
    }
};