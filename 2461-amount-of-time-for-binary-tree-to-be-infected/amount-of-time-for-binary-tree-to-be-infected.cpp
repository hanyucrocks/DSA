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
    int findMaxDist(map<TreeNode*, TreeNode*> &mpp, TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> vis;
        vis[target] = 1;
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            int fl = 0;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    fl = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    fl = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(mpp.count(node) && mpp[node] && !vis[mpp[node]]){
                    fl=1;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }
    TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*> &mpp, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) res = node;
            if(node->left){
                mpp[node->left] = node; 
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right] = node; 
                q.push(node->right);
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = bfsToMapParents(root, mpp, start);
        int maxi = findMaxDist(mpp, target);
        return maxi;
    }
};
