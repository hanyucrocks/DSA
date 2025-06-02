class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> EachRow(numRows);
        int currRow = 0;
        bool goingDown = false;
        for(char c : s){
            EachRow[currRow] += c;
            if(currRow == 0 || currRow == numRows - 1) goingDown =! goingDown;
            currRow += goingDown ? 1 : -1;
        }
        string res;
        for(const string& row : EachRow) res += row;
        return res;
    }
};