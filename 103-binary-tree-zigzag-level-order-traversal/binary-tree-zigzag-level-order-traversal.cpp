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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool lefttoright=true;
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++){
                TreeNode* node = nodesQueue.front(); nodesQueue.pop();
                // find position to fill nodes value
                int index = (lefttoright) ? i : (size-1- i);
                row[index] = node->val;
                if(node->left) nodesQueue.push(node->left);
                if(node->right) nodesQueue.push(node->right);
            }
            lefttoright =! lefttoright;
            ans.push_back(row);
        }
        return ans;
    }
};