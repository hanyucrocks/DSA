class Solution {
public:
    char kthCharacter(int k) {
        // alice has a
        return 'a' + __builtin_popcountll(k - 1);
    }
};