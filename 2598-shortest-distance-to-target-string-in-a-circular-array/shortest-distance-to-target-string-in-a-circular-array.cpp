class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int next = 0;
        int prev = 0;
        int ans = INT_MAX;
        // just find the distance
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                next = (i - startIndex + n) % n;
                prev = (startIndex - i + n) % n;
                ans = min(ans, min(next, prev));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};