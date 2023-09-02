class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using bucket sort
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> buckets(n + 1);
        for(auto it=mp.begin(); it!=mp.end(); it++){
            buckets[it->second].push_back(it->first); //push the numbers which correspond to thier counts
        }

        vector<int> result;
        //now move in reverse direction to find most frequent k elements
        for(int i=n; i>=0; i--){
            if(result.size() >= k)
                break;

            if(!buckets[i].empty()){ //if corresponding to count row is empty
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return result;
    }
};
