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
    void helper(TreeNode* root, int current, int &total){
        if(!root) return;
        current = current * 10 + root->val;
        if(!root->left && !root->right){
            total += current;
            return;
        }
        helper(root->left, current, total);
        helper(root->right, current, total);
    }
    int sumNumbers(TreeNode* root) {
        int total = 0;
        helper(root, 0, total);
        return total;
    }
};