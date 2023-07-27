class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
       unordered_map<int,int> mp; //stores (prefix sum, current index)
       int maxi = 0;
       int sum = 0;
       
       for(int i=0; i<n; i++){
           sum += A[i];
           
           if(sum == 0){
                maxi = i + 1; //index+1 is length
           }
           
            else if(mp.find(sum) != mp.end()){
                maxi = max(maxi, i - mp[sum]); //update to find the longest length
            }
            
            else{
                mp.insert({sum, i});
            }
       }
       return maxi;
    }
};
//TC - O(N)
//SC - O(N)
