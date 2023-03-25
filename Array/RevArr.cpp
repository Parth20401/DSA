#include <bits/stdc++.h>
using namespace std;
    void RevArr(int i,int A[],int N){
        if(i>=N/2)
        return;
         swap(A[i],A[N-i-1]);
        RevArr(i+1,A,N);
        
    }
int main() {
	int t;
	cin>>t;
	while(t--){
	    int N;
	    cin>>N;
	    int A[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>A[i];
	    }
	    RevArr(0,A,N);
	    for(int i=0;i<N;i++){
	        cout<<A[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
