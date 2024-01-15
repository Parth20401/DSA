class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        for (auto& entry : mp) {
            if (entry.second.size() >= 2) {
                for (int j = 1; j < entry.second.size(); j++) {
                    int ans = abs(entry.second[j] - entry.second[j - 1]);
                    if (ans <= k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
