//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
 int getLength(Node* head){
        if(head==NULL)
            return 0;
        Node* temp=head;
        int len=1;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
int getNthFromLast(Node *head, int n)
{
        if(getLength(head)<n)
            return -1;
            
       Node* fast=head;
       Node* slow=head;
       
       for(int i=0;i<n;i++){
           fast=fast->next;
       }
       
       if(fast==NULL)
            return head->data;
            
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
            if(fast==slow)
                return head->data;
            else
                return slow->next->data;
       
}

