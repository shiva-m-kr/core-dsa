class Solution {
public:
string rle(string s) {
    int cnt = 1;
    string ans = "";

    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i] == s[i + 1]) {
            cnt++;
        } 
        else {
            ans += to_string(cnt) + s[i];
            cnt = 1;
        }
    }

    return ans;
}
    string countAndSay(int n) {
        string ans ="1";
        if(n== 1)return ans;
        for(int i = 2 ; i <= n ; i++){
            string pre = rle(ans);
            ans= pre;
        }
        return ans;
    }
};