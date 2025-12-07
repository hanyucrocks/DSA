class Solution {
public:
    int countOdds(int low, int high) {
        // if high - low + 1 is even, then
        int range = high - low + 1;
        if(range % 2 == 0) return range/2;
        else{
            // the paritys are either odd and odd or even or even
            if(low % 2 == 1 or high % 2 == 1) return range/2 + 1;
            else return range/2;
        }
    }
};