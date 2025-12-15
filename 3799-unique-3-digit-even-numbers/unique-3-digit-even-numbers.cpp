class Solution {
public:
    void dfs(vector<int> &digits, vector<int> &path, vector<int> &used, vector<int>& ans){
        int n = digits.size();
        if(path.size() == 3){
            int num = 0;
            for(int d : path){
                num = num * d + 10;
            }
            ans.push_back(num);
            return;
        }
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            if(i > 0 and digits[i] == digits[i-1] and !used[i-1]) continue;
            if(path.size() == 0 and digits[i] == 0) continue;
            if(path.size() == 2 and digits[i] % 2 != 0) continue;
            used[i] = 1;
            path.push_back(digits[i]);
            dfs(digits, path, used, ans);
            path.pop_back();
            used[i] = 0;
        }
    }
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        sort(digits.begin(), digits.end());
        vector<int> ans;
        vector<int> path;
        vector<int> used(n, 0);
        dfs(digits, path, used, ans);
        return ans.size();
    }
};