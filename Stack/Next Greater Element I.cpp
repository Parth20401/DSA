class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        s.push(-1);
        vector<int>ans;
        map<int,int>mp;

        for(int i=nums2.size()-1;i>=0;i--){
            int curr=nums2[i];
            while(s.size()>0 && s.top()<curr){
                s.pop();
            }
            if(s.size()==0)
                mp[curr]=-1;
            else
                mp[curr]=s.top();

            s.push(curr);
        }
        for(int i:nums1){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
