class Solution {
public:
    int maxDepth(string s) {
        int counter = 0, maxcounter = 0;
        for(char c : s){
            if(c == '(') counter++;
            else if(c == ')') counter--;
            maxcounter = max(maxcounter, counter);
        }
        return maxcounter;
    }
};