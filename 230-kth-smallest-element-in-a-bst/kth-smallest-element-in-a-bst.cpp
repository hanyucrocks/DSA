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
    void inorder(TreeNode* node, int &counter, int k, int &smallest){
        if(!node || counter >= k) return;
        // left transverse
        inorder(node->left, counter, k, smallest); counter++;
        if(counter == k){
            smallest = node -> val;
            return;
        }
        inorder(node->right, counter, k, smallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        // inorder will always be sorted, LOR
        int counter = 0;
        int smallest = INT_MIN;
        inorder(root, counter, k, smallest);
        return smallest;
    }
};