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
    bool isLeaf(TreeNode *node){
        return node->left == nullptr and node->right == nullptr;
    }
    int dfs(TreeNode *root, int currentVal){
        if(!root) return 0;
        currentVal = currentVal * 2 + root->val;
        if(isLeaf(root)) return currentVal;
        return dfs(root->left, currentVal) + dfs(root->right, currentVal);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, 0);
    }
};