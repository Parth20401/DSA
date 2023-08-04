class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int, int>> meetings; //to store {start, end}
       for(int i=0; i<n; i++){
           meetings.push_back({start[i], end[i]});
       }
       
       sort(meetings.begin(), meetings.end(), cmp);
       int count = 1;//1 bcos atleast 1 meeting wud be held
       int limit = meetings[0].second;
       
       
       for(int i=1; i<n; i++){
           //if start time of prev meeting is lesser than  time of next meeting, then meeting can be held
           if(meetings[i].first > limit){
               limit = meetings[i].second;
               count++;
           }
       }
       return count;
    }
};
//Tc - O(N log N)
