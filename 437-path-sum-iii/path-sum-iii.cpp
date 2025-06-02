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
    int countPaths(TreeNode* root, long long sum){
        if(!root) return 0;
        int count = 0;
        if(root->val == sum) count++;
        count += countPaths(root->left, sum - root->val);
        count += countPaths(root->right, sum - root->val);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int pathsFromRoot = countPaths(root, targetSum);
        int pathsFromLeft = pathSum(root->left, targetSum);
        int pathsFromRight = pathSum(root->right, targetSum);

        return pathsFromRoot + pathsFromRight+ pathsFromLeft;

    }
};