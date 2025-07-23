class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        stack<char> st;
        string ans = "";

        if (x > y) {
            for (char c : s) {
                if (!st.empty() && st.top() == 'a' && c == 'b') {
                    st.pop();
                    score += x;
                } else {
                    st.push(c);
                }
            }
            ans = "";
            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            for (char c : ans) {
                if (!st.empty() && st.top() == 'b' && c == 'a') {
                    st.pop();
                    score += y;
                } else {
                    st.push(c);
                }
            }

        } else {
            for (char c : s) {
                if (!st.empty() && st.top() == 'b' && c == 'a') {
                    st.pop();
                    score += y;
                } else {
                    st.push(c);
                }
            }
            ans = "";
            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            for (char c : ans) {
                if (!st.empty() && st.top() == 'a' && c == 'b') {
                    st.pop();
                    score += x;
                } else {
                    st.push(c);
                }
            }
        }
        return score;
    }
};
