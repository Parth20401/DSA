/{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int>count;//to store count of each character
		    queue<int>q;
		    string ans="";
		    
		    for(int i=0;i<A.length();i++){
		        char ch=A[i];
		        
		        //store count
		        count[ch]++;
		        
		        //store the characters in a queue
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(count[q.front()]>1) //checking if the char in front is repeating
		                q.pop();
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        //we reach here when q is empty or we found non repeating character
		        if(q.empty())
		            ans.push_back('#');
		    }
		    return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
