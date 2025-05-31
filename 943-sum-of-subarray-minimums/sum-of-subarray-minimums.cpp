class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = prevSmallerElement(arr);
        const int mod = 1e9+7;
        long long total = 0;
    for(int i = 0; i < n; i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
    }
    return total;
    }
    vector<int> nextSmallerElement(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> nse(n, n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> prevSmallerElement(vector<int> &nums){
        int n = nums.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
};