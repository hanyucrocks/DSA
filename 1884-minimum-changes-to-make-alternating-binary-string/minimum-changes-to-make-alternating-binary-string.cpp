class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int c1 = 0, c0 = 0;
        for(int i = 0;i<n;i++){
            char ex1 = (i % 2 == 0) ? '0' : '1';
            char ex2 = (i % 2 == 0) ? '1' : '0';
            if(s[i] != ex1) c1++;
            if(s[i] != ex2) c0++;
        }
        return min(c1, c0);
    }
};