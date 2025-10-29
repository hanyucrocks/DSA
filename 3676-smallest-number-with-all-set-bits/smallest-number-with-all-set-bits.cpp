class Solution {
public:
    int smallestNumber(int n) {
        // x >= n such that binary of x only set bits
        int x = 1;
        while(x <= n) x <<=1;
        return x-1;
    }
};