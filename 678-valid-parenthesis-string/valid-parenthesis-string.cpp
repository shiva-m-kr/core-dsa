class Solution {
public:
 bool checkValidString(string s) {
    stack<int> open;
    stack<int> resolve;

    for(int i = 0 ;i < s.length() ; i++){
        if(s[i] == '('){
            open.push(i);
        }
        else if(s[i] == '*'){
            resolve.push(i);
        }
        else{
            if(!open.empty()){
                open.pop();
            }
            else if(!resolve.empty()){
                resolve.pop();
            }
            else{
                return false;
            }
        }
    }
    while(!open.empty() && !resolve.empty()){
        if(open.top() < resolve.top()){
            open.pop();
            resolve.pop();
        }else{
            return false;
        }
    }
    return open.empty();
 }
};