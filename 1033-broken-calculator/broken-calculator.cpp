class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // if walking backwards help
        // then start from the target
        // multiply becomes divide
        // and subtract becomes add
        int ops = 0;
        //target se start me kaise jaye...
        while(target > startValue){
            // walk back
            if(target % 2 ==0) target /= 2;
            else target += 1;
            ops++; 
        }
        return ops + (startValue - target);
    }
};