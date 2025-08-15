class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0) return 0;
        int i = 0;
        while(1){
            if(pow(4, i) == n) return 1;
            if(pow(4, i) > n) return 0;
            i++;
        }
        return false;
    }
};