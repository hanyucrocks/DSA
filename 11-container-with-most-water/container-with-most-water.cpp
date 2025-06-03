class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxlen = INT_MIN;
        while(l < r){
            int area = (min(height[l], height[r]) * (r - l));
            if(area > maxlen) maxlen = area;
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maxlen;
    }
};