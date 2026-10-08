class Solution {
public:
    bool checkValidString(string s) {
        int x = 0;
        int y = 0;
        for(char ch:s){
            if(ch == '('){
               x++;
               y++;
            }else  if(ch == ')'){
               x--;
               y--;
            }else{
                x--;
                y++;
            }
            if(y < 0) return false;
            if(x < 0) x = 0;
        }
        return x == 0;
    }
};