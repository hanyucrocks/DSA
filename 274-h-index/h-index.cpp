class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int res = 0;
        for(int i = 0; i < citations.size(); i++){
            if(i + 1 <= citations[i]) res = i +1;
        }
        return res;
    }
};