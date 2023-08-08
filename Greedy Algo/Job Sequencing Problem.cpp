class Solution 
{
    public:
    //write a comparator to sort the jobs according to profit in decreasing order
    bool static comparator(Job a, Job b){
        return (a.profit > b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, comparator);
        int maxi = arr[0].dead;
        //find the max deadline
        for(int i=1; i<n; i++){
            maxi = max(maxi, arr[i].dead);
        }
        
        int slot[maxi + 1];
        //assign the values of -1 to every cell in array
        for(int i=0; i<=maxi; i++){
            slot[i] = -1;
        }
        
        int countJobs = 0, jobProfit = 0;
        
        for(int i=0; i<n; i++){
            //we perform a particular job on the last day possible, so that rest spaces are still empty,so move backwards
            for(int j=arr[i].dead; j>0; j--){
                
                if(slot[j] == -1){
                    slot[j] = i; //if empty, assign the job id on that index
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(countJobs);
        ans.push_back(jobProfit);
        return ans;
    } 
};

//TC - O(nlogn + O(n*m)
//SC - O(m)
