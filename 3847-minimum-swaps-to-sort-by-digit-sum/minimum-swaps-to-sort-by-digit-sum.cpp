class Solution {
public:
    
    int sumofdigits(int n) {
        if (!n) return 0;
        return n % 10 + sumofdigits(n / 10);
    }

    int minSwaps(vector<int>& nums1) {
 
        vector<int> nums2 = nums1;


        sort(nums2.begin(), nums2.end(), [this](int a, int b) {
            int x = sumofdigits(a);
            int y = sumofdigits(b);

            if (x == y) return a < b;
            return x < y;
        });

 
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }

        int ans = 0;
        int i = 0;

        while (i < nums1.size()) {
            if (mp[nums1[i]] == i) {
             
                i++;
            } else {
    
                ans++;
                swap(nums1[mp[nums1[i]]], nums1[i]);
            }
        }

        return ans;
    }
};