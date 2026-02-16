class Solution {
public:
    string inttobinary32(int n){
        // if(n==0) return "0";
        string ans = "";
        for(int i = 31; i >= 0; i--){
            if(n & (1 << i)) ans += '1';
            else ans += '0';
        }
        return ans;
    }
    int reverseBits(int n) {
        // some laters than others
        // this commenting thing is ughhhhhhhhhhh i hate ths feeling mannn
        // no more parties in 2013...
        // just reverse the binary string.
        string bin = inttobinary32(n);
        reverse(bin.begin(), bin.end());
        int ans = stoi(bin, nullptr, 2);
        return ans;
    }
};