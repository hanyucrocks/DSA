class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n =s.size();
        // for k, the total tarika is 2^k
        if(n - k + 1 < (1 << k)) return false;
        unordered_set<string> st;
        for(int i = 0; i <= n - k; i++){
            st.insert(s.substr(i, k));
        }
        return st.size() == pow(2, k);
    }
};