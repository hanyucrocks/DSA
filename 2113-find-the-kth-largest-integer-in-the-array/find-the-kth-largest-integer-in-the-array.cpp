class Solution {
public:
    static bool comp(const string &a, const string &b){
        int m = a.size();
        int n = b.size();
        if(m == n){
            return a > b;
        }
        // m has more number than b toh a > b hua hi
        return (m > n);
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        // divide and conquer....
        // sort is needed...
        sort(nums.begin(), nums.end(), comp);
        return nums[k-1];
    }
};