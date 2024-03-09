class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();
        std::vector<std::vector<int>> newIntervals;

        while(i < n && intervals[i][1] < newInterval[0]) {
            newIntervals.push_back(intervals[i++]);
        }

        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0],intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        newIntervals.push_back(newInterval);

        while(i < n) {
            newIntervals.push_back(intervals[i++]);
        }
        return newIntervals;
    }
};
