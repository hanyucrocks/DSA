class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total_pts = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k==n) return total_pts;
        int window = n - k;
        int ans = 0;
        int currsum = 0;
        for(int i = 0; i < window; i++) currsum += cardPoints[i];
        int minisum = currsum;
        for(int i = window; i < n; i++){
            currsum += cardPoints[i] - cardPoints[i-window];
            minisum = min(minisum, currsum);
        }
        return total_pts - minisum;
    }
};