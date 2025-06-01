class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        // ordered_map lenge
        map<int, int> mpp;
        for(int i = 0; i < hand.size(); i++) mpp[hand[i]]++;
        while(!mpp.empty()){
            int curr = mpp.begin()->first;
            for(int i = 0; i < groupSize; i++){
                if(mpp[curr + i] == 0){
                    return false;
                }
                mpp[curr+i]--;
                if(mpp[curr+i ] < 1){
                    mpp.erase(curr+i);
                }
            }
        }
        return true;
    }
};