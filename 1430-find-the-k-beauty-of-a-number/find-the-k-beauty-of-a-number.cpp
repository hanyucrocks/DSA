class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        int ans = 0;
        // l = 0, r = k -1;
        for(int i = 0; i <= n - k; i++){
            string sub =  s.substr(i, k);
            int val = stoi(sub);
            if(val != 0 && num % val ==0) ans++;
        }
    return ans;

    }
};