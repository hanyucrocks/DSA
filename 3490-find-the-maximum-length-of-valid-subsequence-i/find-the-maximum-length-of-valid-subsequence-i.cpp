class Solution {
public:
    int maximumLength(vector<int>& a) {
        int n = a.size();
        // sub1 + sub2
        // odd eve odd even 
        // eve odd eve odd even odd even
        // all odd or all even
        int oddcnt =0, evencnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] % 2) oddcnt++;
            else evencnt++;
        }
        // alt1 starts with even
        int alt1 = 0;
        int expected = 0;
        for(int i = 0; i < n; i++){
            if((a[i] % 2) != expected){
                alt1++;
                expected ^= 1;
            }
        }
        // alt2
        int alt2 = 0;
        expected = 1;
        for(int i = 0; i < n; i++){
            if((a[i] % 2) != expected){
                alt2++;
                expected ^=1;
            }
        }
        int ans = max({oddcnt, evencnt, alt1, alt2});
        return ans;
    }
};