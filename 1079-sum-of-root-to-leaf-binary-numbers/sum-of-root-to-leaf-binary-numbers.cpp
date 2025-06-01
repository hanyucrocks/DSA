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
    bool isLeaf(TreeNode* node) {
    return node->left == nullptr && node->right == nullptr;
}
    int dfs(TreeNode* node, int currentVal){
        if(!node) return 0;
        currentVal = currentVal * 2 + node->val;
        if(isLeaf(node)) return currentVal;
        return dfs(node->left, currentVal) + dfs(node->right, currentVal);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return 0;
        return dfs(root, 0);
    }
};