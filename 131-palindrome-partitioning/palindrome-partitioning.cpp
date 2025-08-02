class Solution {
public:
    void f(string &s, vector<string> &path, vector<vector<string>> &ans, int ind){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = ind; i < s.size(); i++){
            if(check(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                f(s, path, ans, i+1);
                path.pop_back();
            }
        }
    }
    bool check(string &s, int start, int end){
        while(start <= end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        f(s, path, ans, 0);
        return ans;
    }   
};