class Solution {
public:
    int minimumMoves(string s) {
        // xxx to ooo, 3 moves at one time
        int moves = 0;
        for(int i = 0; i < s.length();){
            if(s[i] == 'X'){
                moves++;
                i += 3;
            }
            else i++;
        }
        return moves;
    }
};