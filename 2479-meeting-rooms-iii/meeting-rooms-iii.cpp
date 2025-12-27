class Solution {
public:
    typedef pair<long long, int> P;
    // bool comp( const vector<int> &a, const vector<int> &b){
    //     return a[0] > b[0];
    // }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        /*
        duration = meeting[1] - meeting[0];
        duration
        start = meeting[0], end = meeting[1]
        */
        // for(auto &meeting : meetings){
        //     int start = meeting[0], end = meeting[1];
        // }
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<int> roomsUsedCount(n, 0);
        priority_queue<P, vector<P>, greater<P>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        for(int room = 0; room < n; room++){
            availableRooms.push(room);
        }
        // now lets start
        for(vector<int> &meet:meetings){
            int start = meet[0];
            int end = meet[1];
            long long duration = end-start;
            while(!usedRooms.empty() and usedRooms.top().first <= start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }
            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            }
            else{
                // no room found, pick earlist one
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + duration, room});
                roomsUsedCount[room]++;
            }
        }
        long long resultRoom = - 1;
        long long maxUse = 0;
        for(int room  = 0; room < n; room++){
            if(roomsUsedCount[room] > maxUse){
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }
        return resultRoom;
    }
};