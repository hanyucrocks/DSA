class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int i = 0;
        int cnt = 0;
        int end = n + k -1;
        for(int j = 1; j < end; j++){
            if(colors[(j - 1) % n] == colors[j % n]) i = j;
            else if(j - i + 1 == k){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};