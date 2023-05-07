class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        vector<vector<int>> res;
        //case 1: no overlapping elements before merge intervals
        //compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        //case 2: overlapping of intervals & merging
        while(i < n && newInterval[1] >= intervals[i][0]){//newInterval's last element >= 1st element of an interval
        newInterval[0] = min(newInterval[0], intervals[i][0]); //update starting index for new interval
        newInterval[1] = max(newInterval[1], intervals[i][1]); //update ending index for new interval
        i++;
        }
        res.push_back(newInterval);

        //case 3:no overlapping after merging intervals
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
