#include <bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   
   int n = heights.size();
   int maxArea = 0;
   //for 1 single building
   for(int i=0; i<n; i++){
     int minHeight = INT_MAX;
     for(int j=i; j<n; j++){
       minHeight = min(minHeight, heights[j]);
       maxArea = max(maxArea, minHeight * (j - i + 1));
     }
   }
   return maxArea;
 }
//TC - O(n^2)
