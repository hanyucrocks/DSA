class Solution {
public:
    string makeFancyString(string s) {
    string res;
    for (int i = 0; i < s.size(); ++i) {
        int len = res.size();
        if (len >= 2 && res[len - 1] == s[i] && res[len - 2] == s[i]) {
            continue;
        }
        res += s[i];
    }
    return res;
}
};