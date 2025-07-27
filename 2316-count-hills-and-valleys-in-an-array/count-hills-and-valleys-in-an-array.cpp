class Solution {
public:
    int countHillValley(vector<int>& a) {
        int n = a.size();
        // isnt this peak element
        // for valley, the closest non equal numbers should be greater than i
        // for hill, the closet non equal numbers should be smaller than i
        int cnt = 0;
        for(int i = 1; i < n -1; i++){
            // 0 and n -1 ko consider hi ni karenge
            if(a[i] == a[i-1]) continue;
            int left = i -1;
            int right = i + 1;
            while(left >= 0 and a[left] == a[i]) left--;
            while(right < n and a[right] == a[i]) right++;

            // now count
            if(left >=0 and right < n){
                if(a[i] > a[left] and a[i] > a[right]) cnt++;
                else if(a[i] < a[left] and a[i] < a[right]) cnt++;
            }
            
        }
        return cnt;
    }
};