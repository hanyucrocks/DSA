class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        // the difference
        int mini = INT_MAX;
        for(int i = 1; i < n; i++){
            int diff = abs(arr[i] - arr[i-1]);
            mini = min(mini, diff);
        }
        // min diff is here
        vector<vector<int>> ans;
        for(int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i-1]) == mini){
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};