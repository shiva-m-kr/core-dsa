
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {};

        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;

            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }

            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto it:mp){
            vector<int> temp;

            for(auto p:it.second){
                for(auto val:p.second){
                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
