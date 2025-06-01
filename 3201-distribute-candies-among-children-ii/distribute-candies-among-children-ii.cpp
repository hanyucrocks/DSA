class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // three children
       long long total = 0;
       for(int i = 0; i <= min(n, limit); i++){
        int rem = n - i;
        int low = max(0, rem - limit);
        int high = min(rem, limit);

        if(high >= low){
            total += (high - low +1);
        }
       }
       return total;
    }
};