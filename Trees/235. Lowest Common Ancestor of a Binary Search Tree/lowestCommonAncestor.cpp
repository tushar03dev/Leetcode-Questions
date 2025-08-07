/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        // case 1 both in left side
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
            return leftAns;
        }
        // case 2 both in right side
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }
        
        return root;
    }
};
