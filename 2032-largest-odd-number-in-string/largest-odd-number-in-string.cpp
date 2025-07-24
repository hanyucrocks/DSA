class Solution {
public:
    string largestOddNumber(string num) {
        // what order. order should be 
        int n = num.size();
        // search for the last odd digit
        for(int i = n - 1; i >= 0; i--){
            if((num[i] - '0') % 2 == 1) return num.substr(0, i+1);
        }
        return "";
    }
};