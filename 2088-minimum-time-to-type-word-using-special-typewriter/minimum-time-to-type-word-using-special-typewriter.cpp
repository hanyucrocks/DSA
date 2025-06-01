class Solution {
public:
    int minTimeToType(string word) {
        char curr = 'a';
        int time = 0;
        for(char ch : word){
            int dist = abs(ch - curr);
            int shortestpath = min(dist, 26 - dist);
            time = shortestpath + time + 1;
            curr = ch;
        }
        return time;
    }
};