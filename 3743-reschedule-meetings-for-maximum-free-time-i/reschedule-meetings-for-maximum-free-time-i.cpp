class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<pair<int, int>> events;

        for (int i = 0; i < n; i++) {
            events.emplace_back(startTime[i], endTime[i]);
        }

        sort(events.begin(), events.end());
        int totalTime = events[n - 1].second - events[0].first;
        vector<int> gaps;
        int busyTime = 0;
        for (int i = 0; i < n; i++) {
            busyTime += (events[i].second - events[i].first);
            if (i > 0) {
                int gap = events[i].first - events[i - 1].second;
                gaps.push_back(gap);
            }
        }
        int firstGap = events[0].first;
        int lastGap = eventTime - events[n - 1].second;
        gaps.insert(gaps.begin(), firstGap);
        gaps.push_back(lastGap);
        int maxFree = 0;
        int window = 0;
        int m = gaps.size();

        for (int i = 0; i < m; i++) {
            window += gaps[i];
            if (i >= k + 1) window -= gaps[i - (k + 1)];
            if (i >= k) maxFree = max(maxFree, window);
        }

        return maxFree;
    }
};
