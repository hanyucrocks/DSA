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
    void check(TreeNode* root, int &ans, bool isLeft){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(isLeft) ans += root->val;
            return;
        }
        if(root->left) check(root->left, ans, true);
        if(root->right) check(root->right, ans, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans =0;
        bool isLeft = false;
        check(root, ans, isLeft);
        return ans;
    }
};