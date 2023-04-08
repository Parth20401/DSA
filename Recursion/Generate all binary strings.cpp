//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void find(int num,string ans){
        if(num==0){
            cout<<ans<<" ";
            return;
    }
    find(num-1,ans+'0');
    
    if(ans.size()==0 || ans.back()!='1')
        find(num-1,ans+'1');
}

    void generateBinaryStrings(int& num){
        find(num,"");
        return;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
