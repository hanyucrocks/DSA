class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }
        vector<pair<int, char>> freqVq;
        for(auto &p : freq){
            freqVq.push_back({p.second, p.first});
        }
        string ans = "";
        sort(freqVq.rbegin(), freqVq.rend());
        for(auto &p: freqVq){
            ans += string(p.first, p.second);
        }
        return ans;
    }
};