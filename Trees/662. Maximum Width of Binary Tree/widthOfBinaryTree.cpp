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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long maxi = 1;

        while (!q.empty()) {

            long long start = q.front().second;
            long long end = q.back().second;

            maxi = max(maxi, end - start + 1);
            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* front = q.front().first;
                long long index = q.front().second - start;
                q.pop();
                
                if (front->left)
                    q.push({front->left, 2 * index + 1});
                if (front->right)
                    q.push({front->right, 2 * index + 2});
            }
        }
        return maxi;
    }
};
