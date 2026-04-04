class Solution {
public:
    int n;
    string decodeCiphertext(string encodedText, int rows) {
        n = encodedText.size();
        // wheres the party tonight
        // reverse engg hai ye toh
        int cols = n / rows;
        // 4 cols ho jayega
        // stimulate then move...
        vector<vector<char>> grid(rows, vector<char>(cols, 0));
        // now we put shit inem
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = encodedText[idx];
                idx++;
            }
        }
        string ans = "";
        for(int startCol=0; startCol < cols; startCol++){
            int i = 0, j = startCol;
            while(i < rows and j < cols){
                ans += grid[i][j];
                i++;
                j++;
            }
        }
        while(!ans.empty() and ans.back() == ' ') ans.pop_back();
        return ans;
    }
};