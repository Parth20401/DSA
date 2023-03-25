// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

//Function to merge the arrays.
void merge(int arr1[], int arr2[], int n, int m)
{ 
    int t1,t2,t3;
   int k=n+m;
   int gap=k;
   while(gap!=1){
       if(gap%2!=0)
       gap=(gap+1)/2;
       else gap=gap/2;
       
       int i=0,j=gap;
       while(j<k){
           if(j<n){
               if(arr1[i]>arr1[j]){
               t1=arr1[i];
               arr1[i]=arr1[j];
               arr1[j]=t1;
               }
               
           }
           else if(i<n){
               if(arr1[i]>arr2[j-n]){
               t2=arr1[i];
               arr1[i]=arr2[j-n];
               arr2[j-n]=t2;
               }
           }
           else{
               if(arr2[i-n]>arr2[j-n]){
              t3=arr2[i-n];
              arr2[i-n]=arr2[j-n];
              arr2[j-n]=t3;
           }
           }
           i++;
           j++;
       }
   }
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n,m;
		scanf("%d", &n);
		scanf("%d", &m);
		int *arr1;
		arr1 = (int*)malloc(n * sizeof(int));
		for(int i=0;i<n;i++)
    		scanf("%d", &arr1[i]);
		int *arr2;
		arr2 = (int*)malloc(m * sizeof(int));
		for(int i=0;i<m;i++)
    		scanf("%d", &arr2[i]);
    	
    	merge(arr1,arr2,n,m);
    	for(int i=0;i<n;i++)
    		printf("%d ", arr1[i]);
		for(int i=0;i<m;i++)
    		printf("%d ", arr2[i]);
    	printf("\n");
	}
	return 0;
}  // } Driver Code Ends
