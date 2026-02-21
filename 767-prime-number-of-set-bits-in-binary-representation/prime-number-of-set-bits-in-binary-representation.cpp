class Solution {
    bool isPrime(int n){
        if(n == 1) return false;
        if(n ==2) return true;
        if(n % 2 ==0) return false;
            for(int i = 3; i <= sqrt(n); i+=2){
                if(n % i ==0) return false;
            }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        // yaar ye bit manipulation ki maa ki chut samjhe
            int cnt = 0;
        for(int i = left; i <= right; i++){
            int num = __builtin_popcount(i);
            if(isPrime(num)) cnt++;
        }
        return cnt;
    }
};