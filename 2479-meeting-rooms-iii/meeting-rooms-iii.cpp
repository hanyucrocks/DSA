class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());

    // Free rooms by room index
    priority_queue<int, vector<int>, greater<>> freeRooms;
    for (int i = 0; i < n; ++i)
        freeRooms.push(i);

    // Busy rooms: (endTime, roomNumber)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

    vector<int> roomCount(n, 0);

    for (auto& m : meetings) {
        long long start = m[0], end = m[1];

        // Free up rooms whose meetings have ended by start time
        while (!busy.empty() && busy.top().first <= start) {
            freeRooms.push(busy.top().second);
            busy.pop();
        }

        if (!freeRooms.empty()) {
            int room = freeRooms.top(); freeRooms.pop();
            ++roomCount[room];
            busy.emplace(end, room);
        } else {
            // Delay meeting: use room that gets free first
            auto [endTime, room] = busy.top(); busy.pop();
            ++roomCount[room];
            busy.emplace(endTime + (end - start), room);
        }
    }

    int maxMeetings = *max_element(roomCount.begin(), roomCount.end());
    for (int i = 0; i < n; ++i)
        if (roomCount[i] == maxMeetings)
            return i;

    return -1; // should not reach here
}
};