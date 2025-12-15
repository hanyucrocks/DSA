class Solution {
public:
    void dfs(vector<int> &digits, vector<int> &used, vector<int> &path, vector<int> &ans){
        if(path.size() == 3){
            int num = 0;
            for(int d : path){
                num = num * 10 + d;
            }
            ans.push_back(num); return;
        }
        int n = digits.size();
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            if(i > 0 and digits[i] == digits[i-1] and !used[i-1]) continue;
            if(path.size() == 0 and digits[i] == 0) continue;
            if(path.size() == 2 and digits[i] % 2 != 0) continue;
            used[i] = 1;
            path.push_back(digits[i]);
            dfs(digits, used, path, ans);
            path.pop_back();
            used[i] = 0;
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        // digits where each element is a digit.
        // answer is from 100 to 999
        sort(digits.begin(), digits.end());
        vector<int> ans;
        vector<int> used(n, 0);
        vector<int> path;
        dfs(digits, used, path, ans);
        return ans;
    }
};