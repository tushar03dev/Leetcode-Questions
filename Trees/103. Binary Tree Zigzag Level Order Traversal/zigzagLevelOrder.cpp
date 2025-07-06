/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        bool flag = false;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == NULL) {

                if (flag)
                    reverse(temp.begin(), temp.end());

                ans.push_back(temp);
                temp = {};
                flag = !flag;

                if (!q.empty()) q.push(NULL);

            } else {
                temp.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }
        return ans;
    }
};
