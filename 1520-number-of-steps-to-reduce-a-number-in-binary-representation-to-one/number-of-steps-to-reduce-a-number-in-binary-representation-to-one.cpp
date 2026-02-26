class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ops = 0;
        int carry = 0;
        for(int i = n -1; i>=1; i--){
            int bit = (s[i] - '0') + carry;
            if(bit == 0){
                ops++;
            }
            else if(bit == 1){
                ops+=2;
                carry=1;
            }
            else if(bit==2){
                ops++;
                carry = 1;
            }
        }
        return ops + carry;
    }
};