class Solution {
public:
    string removeOuterParentheses(string s) {
        string split = "";
        int cnt = 0;
        string ans = "";
        for(int i = 0 ; i < s.length() ;i++){
            int ch = s[i];
            split += ch;

            if(ch == '(')cnt++;
            else{
                cnt--;
            }
            if(cnt < 0){
                cnt = 0;
                split ="";
            }

            if(cnt == 0 && split.length() >=2 ){
                string a(split.begin()+1,split.end()-1);
                ans+=a;
                split = "";
                cnt = 0;
            }
        }
        return ans;
    }
};