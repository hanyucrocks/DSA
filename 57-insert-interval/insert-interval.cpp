class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;
        // insert all the intervals before the newinterval
        while(i < n and intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        // now make the interval which is gonna be inserted. min and max concept
        while(i < n and intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // piche wale saare
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};