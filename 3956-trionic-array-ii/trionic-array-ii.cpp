class Solution {
public:
    typedef long long ll;
    
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const ll NEGINF = -4e18;
        ll ans = 0;
        // dp wagera hai
        //
        vector<ll> dp0(n), dp1(n, NEGINF), dp2(n, NEGINF), dp3(n, NEGINF);
        for(int i = 0; i < n; i++){
            // dp0[0] is the max sum of a subraary end at 0, aftrer finishing k of the four phases.
            dp0[i] = nums[i];
        }

        //dpk[i] is the max sum of a subarray end at at i
        int i = 1;
        while(i < n){
            if(nums[i] > nums[i-1]){
                dp1[i] = max(dp1[i-1]+nums[i], dp0[i-1]+nums[i]);
                dp3[i] = max(dp3[i-1]+nums[i], dp2[i-1] + nums[i]);
                dp2[i] = NEGINF;
            }
            else if(nums[i] < nums[i-1]){
                dp1[i] = NEGINF;
                dp2[i] = max(dp2[i-1] + nums[i], dp1[i-1] + nums[i]);
                dp3[i] = NEGINF;
            }
            else{
                // equal me
                dp1[i] = NEGINF;
                dp2[i] = NEGINF;
                dp3[i] = NEGINF;
            }
            i++;
        }
        return *max_element(dp3.begin(), dp3.end());
    }
};