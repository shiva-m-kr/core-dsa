class Solution {
public:
    int MOD = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32,0);

        for(int &num:nums){
            for(int b = 0 ; b < 32 ; b++){
                if(num &(1<<b)){
                    count[b]++;
                }
            }
        }
        long long res = 0;
        while(k--){
            long long curr = 0;
            for(int b = 0 ;b < 32 ; b++){
                if(count[b] > 0){
                    count[b]--;

                    curr = (curr | (1<<b));
                }
            }
            res = (res + (curr*curr))%MOD;
        }
        return res;
    }
};