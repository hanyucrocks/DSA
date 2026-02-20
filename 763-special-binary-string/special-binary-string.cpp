class Solution {
public:
    string makeLargestSpecial(string s) {
        /*
        if the last idx of the s1 is exactly one idx befroe the first char of s2
        s1[n - 1] = 1- s2[0]
        */
        vector<string> subs;
        int n = s.size();
        int cnt = 0, start = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') cnt++;
            else cnt--;
        if(cnt == 0){
            string ok = s.substr(start + 1, i - start - 1);
            subs.push_back("1" + makeLargestSpecial(ok) + "0");
            start = i + 1;
        }
    }
    sort(subs.begin(), subs.end(), greater<string> ());
    string ans;
    for(auto &x : subs) ans += x;
    return ans;
    }
};