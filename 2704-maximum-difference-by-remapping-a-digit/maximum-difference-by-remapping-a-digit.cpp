class Solution {
public:
    int minMaxDifference(int num) {
        // change the sabse chota value to 9
        // change the sabse chota value to 0
        // first non-nine digit to 9
        string str = to_string(num);
        string ma = "";
        string mi = "";
        int n = str.size();
        char ele = ' ';
        // step 1 find first non-9 digit for max
        for (int i = 0; i < n; i++) {
            if (str[i] != '9') {
                ele = str[i];
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (ele == str[i])
                ma += '9';
            else
                ma += str[i];
        }
        for (int i = 0; i < n; i++) {
            if (str[0] == str[i])
                mi += '0';
            else
                mi += str[i];
        }
        return stoi(ma) - stoi(mi);
    }
};