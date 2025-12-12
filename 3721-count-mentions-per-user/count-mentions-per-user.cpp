class Solution {
public:
    void applyMessageEvent(vector<string> event, vector<int> &mentionCount, vector<int> &offlineTime){
        int ts = stoi(event[1]);
        vector<string> ids;
        stringstream ss(event[2]);
        string token;
        while(ss >> token){
            ids.push_back(token);
        }
        //proces all IDS
        for(string id : ids){
            if(id == "ALL"){
                for(int i = 0; i < mentionCount.size(); i++){
                    mentionCount[i]++;
                }
            } else if(id == "HERE"){
                for(int i = 0; i < mentionCount.size(); i++){
                    if(offlineTime[i] == 0 or offlineTime[i] + 60 <= ts){
                        mentionCount[i]++;
                    }
                }
            } else{
                // id1 id2 ... idx
                mentionCount[stoi(id.substr(2))]++;
            }
        }
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentionCount(numberOfUsers);
        vector<int> offlineTime(numberOfUsers);
    auto comp = [](
        auto &vec1, auto &vec2
    ){
        int t1 = stoi(vec1[1]);
        int t2 = stoi(vec2[1]);
        if(t1 == t2){
            return vec1[0][1] > vec2[0][1]; // offline > message ;
        }
        return t1 < t2;
    };
    sort(events.begin(), events.end(), comp);
    for(vector<string>event : events){
        if(event[0] == "MESSAGE"){
        applyMessageEvent(event, mentionCount, offlineTime);
        }
        else{
            int ts = stoi(event[1]);
            int id = stoi(event[2]);
            offlineTime[id] = ts;
        }
    }
    return mentionCount;
    }
};