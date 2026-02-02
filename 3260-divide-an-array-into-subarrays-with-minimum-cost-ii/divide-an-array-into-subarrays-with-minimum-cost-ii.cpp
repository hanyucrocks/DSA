class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll ans = LLONG_MAX;
        int n = nums.size();
        // kya seekhne milega isme....
        // ans += nums[0]; // ye fixed hai
        // sliding window technique?
        // sorting kar rahe ho, toh min chahiye toh min heap??
        // sliding window using set....
        set<P> kmin;
        // {num, index}
        set<P> rem;
        // num, index
        // hash tableeee
        // k - 1 elements chahiye, min chahiye
        ll sum = 0;
        int i = 1;
        while(i <= dist){
            kmin.insert({nums[i], i});
            sum += nums[i];
            if(kmin.size() > k -1){
                P temp = *kmin.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                kmin.erase(temp);
            }
            i++;
        }

        // the window is here. now we can slide.
        while(i < n){
            kmin.insert({nums[i], i});
            sum += nums[i];
            if(kmin.size() > k -1){
                P temp = *kmin.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                kmin.erase(temp);
            }
            ans = min(ans, sum);
            P remove = {nums[i-dist], i-dist};
            if(kmin.count(remove)){
                kmin.erase(remove);
                sum -= remove.first;
                if(!rem.empty()){
                    P temp = *rem.begin();
                    kmin.insert(temp);
                    sum += temp.first;
                    rem.erase(temp);
                }
            } else{
                rem.erase(remove);
            }
            i++;
        }
        return nums[0] + ans;
    }
};