class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int bitAnd = -1;
        for(int i =0 ; i < nums.size() ; i++){
            if(i == nums[i])continue;
            bitAnd = bitAnd & nums[i];
        }
        return bitAnd == -1 ? 0 : bitAnd;
    }
};