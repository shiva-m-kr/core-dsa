class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr long long MOD = 1'000'000'007;

        // prefix sum approach
        int n = arr.size();

        int pref = 0;

        // now moving to the pairup apporach
        long long cnt = 0;
        long long odd = 0;
        long long even = 1; // since 0 is considered as even
        for (int i = 0; i < n; i++) {

            int x = pref + arr[i];
            pref = x;

            if (x % 2 == 0) {
                even++;
                cnt += odd;
            } else {
                odd++;
                cnt += even;
            }
        }
        return cnt % MOD;
    }
};