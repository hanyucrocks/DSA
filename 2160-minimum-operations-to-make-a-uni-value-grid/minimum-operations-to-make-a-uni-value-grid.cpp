class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flat;
        for(auto &p : grid){
            for(auto &val : p){
                flat.push_back(val);
            }
        }
        int ops = 0;
        int mod = flat[0] % x;
        for(int val : flat){
            if(val % x != mod) return -1;
        }
        sort(flat.begin(), flat.end());
        int med = flat[flat.size() / 2];
        for(int val : flat){
            ops += abs(med - val)/x;
        }
        return ops;
    }
};