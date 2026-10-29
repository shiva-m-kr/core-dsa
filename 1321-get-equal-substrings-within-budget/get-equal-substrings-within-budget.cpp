class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0;
        int n = s.length();
        int price = 0;
        int i= 0;
        for(int j = 0; j < n ; j++){
            int cost = abs(s[j]-t[j]);
            price += cost;
            while(price > maxCost){
                price -= abs(s[i]-t[i]);
                i++;
            }
            len = max(len,j-i+1);

        }
        return len;
    }
};