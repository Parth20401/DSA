class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedInterval;
        if(intervals.size() == 0)
            return mergedInterval;

        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];

        //moving pointers
        for(auto it : intervals){
            //if 1st element of next interval <= 2nd element of current interval, then overlapping
            if(it[0] <= tempInterval[1]){
                tempInterval[1] = max(it[1], tempInterval[1]); //updating index
            }
            //if no overlapping
            else{
                mergedInterval.push_back(tempInterval);
                tempInterval = it; //next interval for further processing
            }
        }
            mergedInterval.push_back(tempInterval); //pushing the remaining interval
            return mergedInterval;        
    }
};
