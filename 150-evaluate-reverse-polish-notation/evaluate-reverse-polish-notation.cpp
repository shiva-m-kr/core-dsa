class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){

            string s = tokens[i];

            if(s == "+" || s == "-" || s == "*" || s == "/"){

                int res2 = st.top();
                st.pop();

                int res1 = st.top();
                st.pop();

                if(s == "+"){
                    st.push(res1 + res2);
                }
                else if(s == "-"){
                    st.push(res1 - res2);
                }
                else if(s == "*"){
                    st.push(res1 * res2);
                }
                else if(s == "/"){
                    st.push(res1 / res2);
                }
            }
            else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
