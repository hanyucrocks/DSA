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
    long long totalSum = 0;
    long long ans = 0;
    void getotal(TreeNode* root){
        if(!root) return;
        totalSum += root->val;
        getotal(root->left);
        getotal(root->right);
    }
    long long dfs(TreeNode* root){
        if(!root) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long subtreesum = left + right + root->val;
        ans = max(ans, subtreesum * (totalSum - subtreesum));
        return subtreesum;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        const int mod = 1e9+7;
        /*
        remove one edge.. such that product of the sums of the subtrees. ..wow
        kuch palle ni pad rhaaaa hainnnnn
        1 2 3 4 5 6
        
        */
        getotal(root);
        dfs(root);
        return ans % mod;
    }
};