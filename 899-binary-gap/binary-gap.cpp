class Solution {
public:
    string inttobinary(int n) {
        string ans = "";
        while (n > 0) {
            ans += (n % 2 == 0 ? "0" : "1");
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int binaryGap(int n) {
        // very very whaaaat
        // subah uthke coding ki mkcccc
        string bin = inttobinary(n);
        int lastIdx = -1;
        int maxD = INT_MIN;
        int dist = 0;
        for (int i = 0; i < bin.size(); i++) {
            if (bin[i] == '1') {
                if (lastIdx == -1) {
                    lastIdx = i;
                } else{
                    dist = i - lastIdx;
                    lastIdx= i;
                }
            }
            maxD = max(maxD, dist);
        }
        return maxD;
    }
};