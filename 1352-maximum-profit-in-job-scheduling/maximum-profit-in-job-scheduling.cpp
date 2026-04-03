class Solution {
        int n;
public:
    int getNextIndex(vector<tuple<int, int, int>> &jobs, int start, int currentJobEnd){
        // starting point should be greater than or equal to target
        int end = n - 1;
        int result = n;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(get<0>(jobs[mid]) >= currentJobEnd){
                result = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return result;
    }
    int f(int i, vector<tuple<int, int, int>> &jobs, vector<int> &dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        // current and next job
        // take or not take
        int next = getNextIndex(jobs, i + 1, get<1>(jobs[i]));
        int taken = get<2>(jobs[i]) + f(next, jobs, dp);
        int nottake = f(i+1, jobs, dp);
        return dp[i] = max(taken, nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // n jobs
        // kind of like knapsack ish, overlapping wale nahi chalenge
        n = startTime.size();
        vector<tuple<int, int, int>> jobs;
        for(int i = 0;i<n;i++) jobs.push_back({startTime[i], endTime[i], profit[i]});
        // ab karo sort
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, -1);
        return f(0, jobs, dp);
        // how to find the next job, current[end] <= next[start]
    }
};