	//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int s=0;
	    int e=n-1;
	    int c=0;
	    int mid;
	    while(s<=e)
	    {
	        
	        if(arr[mid]>x)
	        e=mid-1;
	        else if(arr[mid]<x)
	        s=mid+1;
	       else{
	        c++;
	        int i=mid-1;
	        int j=mid+1;
	        while(i>=s && arr[i]==x){
	        c++;
	        i--;}
	        while(j<=e && arr[j]==x){
	        c++;
	        j++;        
	       }
	        break;
	    }
	    mid=s+(e-s)/2;
	    }
	    return c;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
