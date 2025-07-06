/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(map<int,vector<pair<int,int>>>& mp, TreeNode* root, int row, int col){
        if(!root) return;

        mp[col].push_back({row, root->val});

        solve(mp,root->left,row+1,col-1);
        solve(mp,root->right,row+1,col+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> mp;
        int col = 0, row = 0;
        solve(mp,root, col, row);
        for(auto &[key, vec] : mp){
            sort(vec.begin(),vec.end());
            vector<int> temp;
            for(auto &[row,val] : vec){
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
