class Solution {
public:
    int countMonobit(int n) {
        return n == 0 ? 1 : 1 + (int)log2(n+1);
    }
};