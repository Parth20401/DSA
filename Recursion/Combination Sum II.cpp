class Solution {
public:
    void findCombination(int index,int target,vector<int>& candidates,vector<int>& output,vector<vector<int>>& ans){
        //base case
        if(target==0){
            ans.push_back(output);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) //check for suplicate elements
                continue;
            if(target < candidates[i]) //target becomes less than next element
                break;
            output.push_back(candidates[i]);
            findCombination(i+1,target - candidates[i],candidates,output,ans);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        findCombination(0,target,candidates,output,ans);
        return ans;
    }
};
