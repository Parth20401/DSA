class Solution
{
    public:
    //write comaparator to sort the array acc to val/wt in dec order
    bool static comparator(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comparator);
        
        int currWeight = 0;
        double finalValue = 0.0;
        
        for(int i=0; i<n; i++){
            //if the weights completely fill the knapsack
            if(currWeight + arr[i].weight <= W){
                currWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            //if not fully fit in knapsasck, then take a fraction
            else{
                int remain = W - currWeight; //to find the weight remaining
                finalValue += ((double)arr[i].value / (double)arr[i].weight) * remain; //take the value per wight and multiply with remaining amt
                break;
            }
        }
        return finalValue;
    }
        
};
//TC - O(nlogn + n)
//SC - O(1)
