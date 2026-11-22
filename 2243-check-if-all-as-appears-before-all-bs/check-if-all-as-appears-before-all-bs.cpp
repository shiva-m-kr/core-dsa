class Solution {
public:
    bool checkString(string s) {
        bool check = false;
        for(int i = 0 ; i< s.length() ; i++){
            if(s[i] == 'b'){
                check = true;
            }if(s[i] == 'a' && check){
                return false;
            }
        }
        return true;
    }
};