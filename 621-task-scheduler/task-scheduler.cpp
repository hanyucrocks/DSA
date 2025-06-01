class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        priority_queue<int> pq;
        for(char task : tasks){
            freq[task]++;
        }
        
        for(auto &pair: freq){
            pq.push(pair.second);
        }
        int time = 0;

        while(!pq.empty()){
            vector<int> temp;
            int cycle = n + 1;
            while(cycle > 0 && !pq.empty()){
                int count = pq.top(); pq.pop();
                if(count > 1) temp.push_back(count - 1);
                time++;
                cycle--;
            }
            for(int rem : temp) pq.push(rem);
            if(pq.empty()) break;
            time += cycle;
        }
        return time;
    }
};