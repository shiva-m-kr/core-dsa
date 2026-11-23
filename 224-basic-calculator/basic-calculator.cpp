class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int res = 0;
        long long num = 0;
        int sign = 1;
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            if(isdigit(s[i])){
                num = num*10+(s[i]-'0');
            }else if(s[i] == '+'){
                res += (num*sign);
                num = 0 ;
                sign = 1;
            }
            else if(s[i] == '-'){
                res += (num*sign);
                num = 0 ;
                sign = -1;
            }else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                num = 0;
                sign = 1;
            }else if(s[i] == ')'){
                res += (num*sign);
                num = 0;
                int last_sign = st.top();
                st.pop();
                int last_res = st.top();
                st.pop();
                res *= last_sign;
                res += last_res;
                
            }
        }
        res += (num*sign);

         return res;
    }
};