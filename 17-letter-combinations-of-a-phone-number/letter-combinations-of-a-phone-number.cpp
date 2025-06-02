class Solution {
public:
    void func(int ind, string &digits, unordered_map<char, string> &mp, string &path, vector<string> &res){
        if(ind == digits.size()){
            if(!path.empty()){
                res.push_back(path);
            }
                return;
            }
            for(char ch : mp[digits[ind]]){
                path.push_back(ch);
                func(ind+1, digits, mp, path, res);
                path.pop_back();
            }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> res;
        string path;
        func(0, digits, mp, path, res);
        return res;
    }
};