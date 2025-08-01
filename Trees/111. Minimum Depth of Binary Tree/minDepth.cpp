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
    void solve(TreeNode* root, int& ans,int temp){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans = min(ans,temp);
            return;
        }

        solve(root->left,ans,temp+1);
        solve(root->right,ans,temp+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MAX;
        int temp= 1;
        solve(root,ans,temp);
        return ans == INT_MAX ? 0 : ans;
    }
};
