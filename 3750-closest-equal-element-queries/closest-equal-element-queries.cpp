class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0;i<n; i++) m[nums[i]].push_back(i);
        vector<int> ans;
        for(int q : queries){
            int v = nums[q];
            auto &vec = m[v];
            if(vec.size() == 1){
                ans.push_back(-1);
                continue;
            }
            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            int res = INT_MAX;
            int right = vec[(pos + 1) % vec.size()];
            res = min(res, min(abs(q-right), n - abs(q-right)));
            int left = vec[(pos - 1 + vec.size()) % vec.size()];
            res = min(res, min(abs(q - left), n - abs(q-left)));
            ans.push_back(res);
        }
        return ans;
    }
};