class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
       unordered_map<int, vector<int>> mp;

      for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            mp[size].push_back(i);

            
            if (mp[size].size() == size) {
                result.push_back(mp[size]);
                mp[size].clear();
            }
        }
       return result;

    }
};