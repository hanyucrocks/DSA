class Solution {
public:
    // int f(int i, int j, vector<vector<char>> &matrix, vector<vector<int>> &dp){
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     if(i < 0 or j < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     // left or right directions? dp kaaaam NAHI KAREGA IDHARRRRRRRRRRRRRRRRRRR   
    // }
    int largestRectangleArea(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        int largestarea = INT_MIN;
        int area, nse, pse;
        // traverse the array
        for(int i = 0;i < n; i++){
            // work on the stack
            while(!st.empty() and heights[st.top()] >= heights[i]){
                // get the top and pop it
                int ind = st.top();
                st.pop();
                // nse and pse stuff
                pse = st.empty() ? -1 : st.top();
                // nse is the index
                nse = i;
                area = heights[ind] * (nse-pse - 1);
                largestarea = max(largestarea, area);
            }
            st.push(i);
        }
        // for elements that are not popped from the stack.
        while(!st.empty()){
            nse = n;
            int ind = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            area = heights[ind] * (nse-pse - 1);
                largestarea = max(largestarea, area);
        }
        return largestarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // n rows and m cols
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        // this is a problem of monotonic stack!!!!
        /*
        per row just use the maximum area concept of histogram....
        prefix sum to use the 2d matrix. use row wize
        */
       vector<int> heights(m, 0);
        // height is done,. now what, prefix sum
       for(int i = 0; i < n; i++){
        for(int j  = 0; j < m; j++){
            if(matrix[i][j] == '1') heights[j]++;
            else heights[j] = 0;
        }
        ans = max(ans, largestRectangleArea(heights));
       }
        return ans;
    }
};