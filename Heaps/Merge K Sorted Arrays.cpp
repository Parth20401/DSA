#include <bits/stdc++.h>
class node{
    public:
    int data;
    int i; //row
    int j; //column

    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};
//comparator class for min Heap.
class compare{
    public:
     bool operator()(node*a, node*b){
         return a->data > b->data; 
     }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;

    //Step 1: saare arrays ke 1st elements insert krne hai
    for(int i=0; i<k; i++){
        //create a new node
        node* temp = new node(kArrays[i][0], i, 0); //creating node and accessing value at that index
        minHeap.push(temp);
    }

    vector <int> ans;
    //step 2
    while(minHeap.size() > 0){
        node* temp = minHeap.top();
        ans.push_back(temp->data); //insering top element into ans
        minHeap.pop();
  
        //accessing values of row and column
        int i = temp->i;
        int j = temp->j;

        //check for the next element of the horizontal vector
        if (j + 1 < kArrays[i].size()) {
          node *next = new node(kArrays[i][j + 1], i, j + 1); // making a new node and inserting the next element
          minHeap.push(next);
            }
        }
    return ans;
    }

//TC - O(n*klog(k))
//SC - O(n*k)

