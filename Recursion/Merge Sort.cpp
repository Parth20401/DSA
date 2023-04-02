class Solution {
public:
    vector<int> merge(vector<int>& left,vector<int>& right){
        //int mid=s+(e-s)/2;

        int len1 = left.size();
        int len2 = right.size();

        vector<int>res;
        //merge 2 sorted arrays
        int index1 = 0;
        int index2 = 0;
       // mainArrayindex = s;

        while(index1<len1 && index2<len2){
            if(left[index1] < right[index2])
                res.push_back(left[index1++]);
            else
                res.push_back(right[index2++]);
        }

        //for remaining values
        //left part 
            while(index1<len1){
                res.push_back(left[index1++]);        
                    }

            //right part
             while(index2<len2){
                  res.push_back(right[index2++]);
            }
            return res;
    }

    vector<int> solve(vector<int>& nums,int s,int e){

        //base case
        if(s>=e)
            return {nums[s]};
        int mid = s+(e-s)/2;

        vector<int> left = solve(nums,s,mid); //sorting left part

         vector<int> right = solve(nums,mid+1,e); //sorting right part

        return merge(left,right); //merge two sorted arrays

    }

    vector<int> sortArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
