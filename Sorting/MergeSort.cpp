class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
       int l_sz=m-l+1;
      int L[l_sz+1];
      
       int r_sz=r-m;//r-(mid+1)+1
       int R[r_sz+1];
       
       for( int i=0;i<l_sz;i++)
       L[i]=arr[i+l];
       
       for(int j=0;j<r_sz;j++)
       R[j]=arr[j+m+1];
       
      // L[l_sz]=R[r_sz]=INT_MAX;
      int l_i=0;
      int r_i=0;
      int x_i=l;
      
      while(l_i<l_sz && r_i<r_sz){
          if(L[l_i]<=R[r_i]){
              arr[x_i++]=L[l_i++];
          }
          else {
              arr[x_i++]=R[r_i++];
              
          }
      }
      
      while(l_i < l_sz){
            arr[x_i++] = L[l_i++];
        }
        
        while(r_i < r_sz){
            arr[x_i++] = R[r_i++];
        }
      
    
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(r>l){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    }
};
