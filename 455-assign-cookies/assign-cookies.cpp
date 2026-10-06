class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = 0;
        int cnt = 0;
        for(int i = 0; i <g.size() &&  j < s.size(); i++){
             if(s[j] >= g[i]){
                j++;
                cnt++;
            }else{
                j++;

                i--;
            }
        }
        return cnt;
    }
};