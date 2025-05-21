/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr==NULL) s.append("#, ");
            else s.append(to_string(curr->val) + ',');
            if(curr!=NULL){
                q.push(curr->left); q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         if (data.empty()) return nullptr;

    stringstream s(data);
    string token;

    // Get root value
    getline(s, token, ',');
    TreeNode* root = new TreeNode(stoi(token));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();

        // LEFT
        if (!getline(s, token, ',')) break;
        if (token != "#") {
            try {
                TreeNode* leftNode = new TreeNode(stoi(token));
                node->left = leftNode;
                q.push(leftNode);
            } catch (...) {
                node->left = nullptr;
            }
        }

        // RIGHT
        if (!getline(s, token, ',')) break;
        if (token != "#") {
            try {
                TreeNode* rightNode = new TreeNode(stoi(token));
                node->right = rightNode;
                q.push(rightNode);
            } catch (...) {
                node->right = nullptr;
            }
        }
    }
    return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));