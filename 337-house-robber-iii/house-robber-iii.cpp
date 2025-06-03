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
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0, 0}; // rob_this, skip_this
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        // rob or skip, if rob, then rob this one and then its children's children
        int rob_this = root->val + left.second + right.second;
        int skip_this = max(left.first, left.second) + max(right.first, right.second);
        return {rob_this, skip_this};
    }
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};