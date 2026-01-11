class Solution {
public:
    typedef long long ll;
    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n - 1; i>=0;i--){
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int> &arr){
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() and arr[st.top()] > arr[i]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9+7;
        // how many subarrays can be formed. n * (n+1)/2;
        // stack<int> st;
        // apparently this question is faltu ka hard......
        // prev[i] * next[i] * nums[i] = x, sum of all x is the answer.
       // nse * psee * nums[i] combo 
       vector<int> nse = findNSE(arr);
       vector<int> psee = findPSEE(arr);    
       ll total = 0;
       for(ll i = 0; i < n; i++){
        ll left = i - psee[i];
        ll right = nse[i] - i;
        total = (total + (right * left % mod) * arr[i]) % mod;
       }
       return total;
    }
}; 