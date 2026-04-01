class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        struct Robot {
            int pos, health, idx;
            char dir;
        };

        vector<Robot> robots;
        robots.reserve(n);

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], i, directions[i]});
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        vector<int> st; // indices in robots[]
        for (int i = 0; i < n; i++) {
            if (robots[i].dir == 'R') {
                st.push_back(i);
            } else {
                while (!st.empty() && robots[i].health > 0) {
                    int j = st.back();

                    if (robots[j].health < robots[i].health) {
                        st.pop_back();
                        robots[i].health--;
                        robots[j].health = 0;
                    } 
                    else if (robots[j].health > robots[i].health) {
                        robots[j].health--;
                        robots[i].health = 0;
                    } 
                    else {
                        robots[j].health = 0;
                        robots[i].health = 0;
                        st.pop_back();
                    }
                }
            }
        }

        vector<pair<int,int>> alive;
        for (auto &r : robots) {
            if (r.health > 0) alive.push_back({r.idx, r.health});
        }

        sort(alive.begin(), alive.end());

        vector<int> ans;
        ans.reserve(alive.size());
        for (auto &p : alive) ans.push_back(p.second);

        return ans;
    }
};