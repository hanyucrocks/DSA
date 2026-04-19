class Solution {
    int f(int n){
        int ans = 0;
        while(n != 0){
            int t=n%10;
            ans = ans*10+t;
            n/=10;
        }
        return ans;
    }
public:
    int mirrorDistance(int n) {
        // why is thatttttt
        return abs(n - f(n));
    }
};