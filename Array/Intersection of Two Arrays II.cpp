class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto i : nums1)
            mp[i]++;

        for(const auto& num : nums2){
            if(mp.find(num) != mp.end() && mp[num] > 0){ // && mp[num] > 0
                ans.push_back(num);
                mp[num]--;
            }
        }
        return ans;
    }
};
