class Solution {
public:
    unordered_map<string, bool> t;

    bool dallas(string curr, unordered_map<string, vector<char>> &hash, int ind, string above){
        string key = curr + "_" + to_string(ind) + "_" + above; // very fucking important key. 
        if(curr.length() == 1) return t[key]=true; 
        if(t.count(key)) return t[key];
        if(ind == curr.length() - 1) return t[key] = dallas(above, hash, 0, "");
        string pair = curr.substr(ind, 2);
        if(hash.find(pair) == hash.end()) return t[key]=false;
        for(char &ch : hash[pair]){
            above.push_back(ch);
            if(dallas(curr, hash, ind+1, above) == true) return t[key]=true;
            above.pop_back();
        }
        return t[key]=false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // staking blocks to form a pyramid.
        /*
        allowed = 0 and 1 are left and right.
        BCD, allowed = BCC CDE CEA FFF

        
        */
        unordered_map<string, vector<char>> hash;
        for(auto &pattern : allowed){
            hash[pattern.substr(0, 2)].push_back(pattern[2]); // ABC
        }
        return dallas(bottom, hash, 0, "");

    }
};