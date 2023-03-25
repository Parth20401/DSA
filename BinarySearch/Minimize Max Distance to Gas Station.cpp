//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(double mid,vector<int>&stations,int K){
        int stationsToAdd=0;
        for(int i=0;i<stations.size()-1;i++){
            stationsToAdd+=floor((stations[i+1]-stations[i])/mid);
        }
        return stationsToAdd<=K;
    }
    double findSmallestMaxDist(vector<int> &stations, int K){
      double s=0.0;
      double e=stations[stations.size()-1]-stations[0];
      double mid;
      //double ans=-1;
      while(e-s>1e-6){
          mid=s+(e-s)/2.0;
          if(isPossible(mid,stations,K)){
              e=mid;
          }
          else
                s=mid;
      }
      return s+0.000001;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
