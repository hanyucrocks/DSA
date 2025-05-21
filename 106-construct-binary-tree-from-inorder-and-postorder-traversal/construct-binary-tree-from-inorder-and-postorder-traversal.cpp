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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &mpp){
        if(ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = mpp[postorder[pe]];
        int numsleft = inRoot - is;
        root->left = buildTree(inorder, is, inRoot-1, postorder, ps, ps+numsleft-1, mpp);
        root->right = buildTree(inorder, inRoot+1, ie, postorder, ps+numsleft, pe-1, mpp);
        return root;
    }
};