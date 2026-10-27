class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s ="";
        for(int i = 0 ; i < m-1 ; i++){
            int temp = n;
            while(temp--){
                if(s.length() == 0){
                    s+="."; // har row ka first elementis .
                }else{
                    s += "#";
                }
            }
            ans.push_back(s);
            s ="";
        }
        // last row should be all dot .
        while(n--){
            s += ".";
        }
        ans.push_back(s);
        return ans;
    }
};