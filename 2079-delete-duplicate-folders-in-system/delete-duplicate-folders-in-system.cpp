
struct TrieNode {
    string name;
    unordered_map<string, TrieNode*> children;
    string serial;
    bool deleted = false;

    TrieNode(string n = "") : name(n) {}
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    unordered_map<string, vector<TrieNode*>> hashmap;

    void insert(const vector<string>& path) {
        TrieNode* node = root;
        for (const string& folder : path) {
            if (!node->children.count(folder))
                node->children[folder] = new TrieNode(folder);
            node = node->children[folder];
        }
    }

    string serialize(TrieNode* node) {
        if (node->children.empty()) {
            node->serial = "()";
            return node->serial;
        }

        vector<pair<string, string>> subs;
        for (auto& [childName, childNode] : node->children) {
            string childSerial = serialize(childNode);
            subs.push_back({childName, childSerial});
        }

        sort(subs.begin(), subs.end());
        string s;
        for (auto& [name, sub] : subs) {
            s += "(" + name + sub + ")";
        }
        node->serial = s;
        hashmap[s].push_back(node);
        return s;
    }

    void markDuplicates() {
        for (auto& [s, nodes] : hashmap) {
            if (nodes.size() > 1) {
                for (TrieNode* node : nodes)
                    node->deleted = true;
            }
        }
    }

    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (!child->deleted) {
                path.push_back(name);
                result.push_back(path);
                collect(child, path, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (const auto& path : paths) insert(path);
        serialize(root);
        markDuplicates();
        vector<vector<string>> result;
        vector<string> path;
        collect(root, path, result);

        return result;
    }
};
