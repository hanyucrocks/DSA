class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // check for any number number? any? would that not make any sense, phir count its divisors, if the divisors 4, then sum all the divisors and output.
        for(int num : nums){
        int cnt = 0, sum = 0;
            for(int i = 1; i * i <= num; i++){
                if(num % i == 0){
                    // this is the complete divisor this is the number itself.
                    if(i * i == num){
                        // perfect square only one divisor
                        cnt++;
                        sum += i;
                    }
                    else{
                        cnt+=2;
                        sum += i + num/i;
                    }
                }
            }
                if(cnt == 4){
                    ans += sum;
                }
        }
        return ans;
    }
};