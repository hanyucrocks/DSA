class Solution {
public:
    string inttobinary32(int n){
        string ans = "";
        while(n > 0){
            ans += (n % 2 == 0 ? '0' : '1');
            n/=2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool hasAlternatingBits(int n) {
        bool ok = true;
        string ans = inttobinary32(n);
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] == ans[i-1]){
                ok = false;
                break;
            }
        }
        return ok;
    }
};