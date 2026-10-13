class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans =0 ;
        int n = nums.size();
        for(int i = 0 ;i < n ; i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long a = 0;
        long long b = 0;
        for(int i = 0 ; i < n ; i++){
            if(i < n/2){
                a += nums[i]*nums[i];
            }else{
                b += nums[i]*nums[i];
            }
        }
        return b-a;
    }
};