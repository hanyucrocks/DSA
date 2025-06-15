class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=0;
        for(int i = 0; i <= heights.size() -1; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(heights[element] * (nse - pse - 1), maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = heights.size();
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(heights[element] * (nse - pse - 1), maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // take the histogram approach
        // row by row niche move karenge
        int maxA = 0;
            vector<int> height(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxA = max(maxA, area);
        }
        return maxA;
    }
};