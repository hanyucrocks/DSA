class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        list<int> st;
        for(int i = 0; i< n; i++){
            if(asteroids[i] > 0) st.push_back(asteroids[i]); // positives saare andar
            // lets handle negatives now
            else{
                while(!st.empty() and st.back() > 0 and st.back() < abs(asteroids[i])) st.pop_back(); // smaller wala asteroid gaya
                if(!st.empty() and st.back() == abs(asteroids[i])) st.pop_back();
                else if(st.empty() or st.back() < abs(asteroids[i])) st.push_back(asteroids[i]);
            }
        }
        // positive goes right negative goes left   
        return vector<int> (st.begin(), st.end());
    }
};