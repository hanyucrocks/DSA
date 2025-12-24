class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        /*
        what is happening....
        apple 0 1 apple
        1 3 2
        1 2 3 4 5
        sliding window with k approach?

        15
        2 2 4 7
        */
        sort(capacity.begin(), capacity.end());
        int sum = 0;
        for(int i = 0; i <n;i++){
            sum += apple[i];
        }
        int cnt = 0;
        int total = 0;
        for(int i = m - 1; i >=0; i--){
            total += capacity[i];
            cnt++;
            if(total >= sum)
                break;
        }
        return cnt;
    }
};