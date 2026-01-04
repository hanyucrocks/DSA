class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // O1 space matlab inplace karna hai...
        int n = nums.size();
        int k = 1;
        // the answer lies between 1 to n.
        // sort(nums.begin(), nums.end());
        // for(int num : nums){
        //     if(num < k) continue;
        //     if(num == k) k = k + 1;
        //     else return k;
        // }
        // return k;
        // unordered_set<int> hash;
        // for(int x : nums){
        //     if(x > 0)hash.insert(x);
        // }
        // while(true){
        //     if(hash.find(k)==hash.end()) return k;
        //     k =k+1;
        // }
        vector<bool> present(n, false);
        for(int num : nums){
            if(1 <= num and num <= n) present[num] = true;
        }
        for(int i = 1; i <=n; i++){
            if(present[i] == false) return i;
        }
        return n+1;
    }
};