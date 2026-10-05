class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int a = 0 ;
        int b =1 ;
        int n = nums.size();
        vector<int> res(n,0);
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] >= 0){
                res[a] = nums[i];
                if(a+2 < n)a = a +2 ;
            }else{
                res[b] = nums[i];
               if(b+2 < n)  b += 2;
            }
        }
        return res;
    }
};