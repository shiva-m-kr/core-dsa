class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> store(n);
        for(int i = 0 ; i< n ; i++){
            store[i] = to_string(nums[i]);
        }
        sort(store.begin(),store.end(),[](string a, string b){
            return a + b > b + a;
        });
        if(store[0] == "0") return "0";
        string ans ="";
        for(int i = 0; i < n ; i++){
            ans += store[i];
        }
        return ans;
    }
};