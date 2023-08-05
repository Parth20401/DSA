    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int count = 1;
    	int i = 1;
    	int j = 0;
    	int ans = 1;
    	
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){ //one more platform needed
    	        count++;
    	        i++;
    	    }
    	    else{   //pltaform is reduced
    	        count--;
    	        j++;
    	    }
    	    ans = max(ans, count);
    }
    return ans;
  }
};
