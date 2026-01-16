class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int mod = 1e9+7;
        // whats gonna be the best man
        vector<int> h;
        vector<int> v;
        h.push_back(1);
        for(int x : hFences){
            h.push_back(x);
        }
        h.push_back(m);
        v.push_back(1);
        for(int x : vFences){
            v.push_back(x);
        }
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        unordered_set<int> s;
        for(int i = 0; i < h.size(); i++){
            for(int j = i + 1; j < h.size(); j++){
                s.insert(h[j] - h[i]);
            }
        }
        long long best = -1;
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                int width = v[j] - v[i];
                if(s.find(width)!=s.end()){
                    best = max((int)best, width);
                }
            }
        }
        if(best == -1) return -1;
        else return (best  %mod *best %mod ) % mod;
    }
};