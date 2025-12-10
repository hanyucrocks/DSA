class Solution {
public:
        int mod = 1e9+7;
    long long f(int x){
       long long res = 1;
       for(int i = 1; i <= x; i++){
        res = (res * i) % mod;
       }
       return res;
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int first = complexity[0];
        for(int i = 1; i <n; i++){
            if(complexity[i] <= first) return 0;
        }
        return (int)f(n-1);
    }
};