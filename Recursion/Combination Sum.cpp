class Solution {
public:
    void findCombination(int index,int target,vector<int>& candidates,vector<int>& output,vector<vector<int>>& ans){
        //base case
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(output);
        }
                return;
        }

        //pick an element
        if(target >= candidates[index]){
            output.push_back(candidates[index]); //push the element if it is valid
            findCombination(index,target - candidates[index],candidates,output,ans); //recurisve call
            //now backtrack
            output.pop_back();
        }
        //not pick an element
        findCombination(index+1,target,candidates,output,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output; //store single combination
        findCombination(0,target,candidates,output,ans);
        return ans;
    }
};
