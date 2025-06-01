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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for(int i = 0; i < inorder.size(); i++) mpp[inorder[i]] = i;
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int> &pre, int ps, int pe, vector<int> &ino, int is, int ie, map<int, int> &mp){
        if(ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(pre[ps]);
        int inRoot = mp[root->val];
        int numsleft = inRoot - is;
        root->left = buildTree(pre, ps+1, ps+numsleft, ino, is, inRoot-1, mp);
        root->right = buildTree(pre, ps +numsleft +1, pe, ino, inRoot+1, ie, mp);
        return root;
    }
};