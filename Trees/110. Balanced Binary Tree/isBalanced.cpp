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
    bool isbalanced = true;
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);

        if(isbalanced && abs(leftH-rightH) > 1){
            isbalanced = false;
        }

        return max(leftH, rightH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        height(root);
        return isbalanced;
    }
};
