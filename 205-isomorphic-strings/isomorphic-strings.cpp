class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // s and t are isomorphic
        int n = s.size();
        unordered_map<char, char> mapS;
        unordered_map<char, char> mapT;
        for(int i = 0; i < n; i++){
            char cs = s[i];
            char ct = t[i];
            if(mapS.count(cs) && mapS[cs]!=ct) return 0;
            if(mapT.count(ct) && mapT[ct]!=cs) return 0;
            mapS[cs] = ct;
            mapT[ct] = cs;
        }
        return true;

    }
};