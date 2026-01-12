class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();
        // k letters pakado from starting and just reverse.
        // how do i stimulate this....
        for(int i = 0; i < k/2; i++){
            swap(s[i], s[k-i-1]);
        }
        return s;
    }
};