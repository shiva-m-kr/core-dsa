class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<int> st;
       int n = s.length();
       for(char ch : s){
        if( !st.empty() && ch == ')' && st.top() == '('){
            st.pop();
        }else{
            st.push(ch);
        }
        
       }
       return st.size();
    }
};