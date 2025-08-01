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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int count = 1;
        long long sum = (long long) root->val;
        vector<double> ans;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == NULL) {

                double avg = (double) sum / count;
                ans.push_back(avg);
                sum = 0;
                count = 0;

                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                count++;
                sum += front->val;

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};
