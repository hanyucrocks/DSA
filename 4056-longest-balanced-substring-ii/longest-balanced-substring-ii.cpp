class Solution {
public:
    int helper(string &s, int ch1, int ch2){
        int n = s.size();
        unordered_map<int, int> diffMap;
        diffMap[0] = -1;
        int start = -1;
        int cnt1= 0;
        int cnt2 = 0;
        int maxL = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != ch1 and s[i] != ch2){
                // now break the damn thing
                diffMap.clear();
            diffMap[0] = i;   // base from next index
            cnt1 = cnt2 = 0;
            start = i;
            continue;
            }
            if(s[i] == ch1) cnt1++;
            if(s[i] ==  ch2) cnt2++;
            if(ch1 == ch2){
                maxL = max(maxL, cnt1+cnt2);
            }
            int diff = cnt1-cnt2;
            if(diffMap.count(diff)) maxL = max(maxL, i - diffMap[diff]);
            else diffMap[diff] = i;
        }
        return maxL;
    }
    int longestBalanced(string s) {
        int n = s.size();
        // constraints are big. so no brute forces
        // its gonna be hashing!!!
        // sabse bada substring dhundna hai... thats it
        // sirf a ya b ya c.. isnt this dicey
        // return 0;
        // 3 cases. all equal, 2 disinct characs and all three chars present
        // case 1
        // unordered_map<int, int> hash = {a, b, c};
        int ans = 0;
            int cnt = 1;
            int maxL = 1;
        int ans1 = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]){
                cnt++;
            }
            else{
                maxL = max(maxL, cnt);
                cnt=1;
            }
            maxL = max(maxL, cnt);
        }
        // ans1 = maxL;
        // ans = max(ans, maxL);
        // return ans;
        // case 2
        // ignore the third char
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));
        // case 3 now
        int cntA = 0, cntB = 0, cntC = 0;
        unordered_map<string, int> diffMap2;
        diffMap2["0_0"] = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') cntA++;
            if(s[i] == 'b') cntB++;
            if(s[i] == 'c') cntC++;
            if(cntA == cntB and cntA == cntC) maxL = max(maxL, cntA+cntB+cntC);
            int diffAB = cntA - cntB;
            int diffAC = cntA - cntC;
            string key = to_string(diffAB) + "_" + to_string(diffAC);
            if(diffMap2.count(key)) maxL = max(maxL, i - diffMap2[key]);
            else diffMap2[key] = i;
        }
        return maxL;
    }
};