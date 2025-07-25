class Solution {
public:
    int maxSum(vector<int>& nums) {
        // delete any number of elements from nums without making it empty.
       unordered_set<int> unique;
       int maxElem = INT_MIN;
       int sum = 0;
       for(int num : nums){
        maxElem = max(maxElem, num);
        if(num > 0) unique.insert(num);
       }
       if(maxElem < 0) return maxElem;
       for(int val : unique) sum += val;
       return sum;
    }
};