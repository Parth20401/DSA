#include <bits/stdc++.h> 
using namespace std;

void sortedInsert(stack<int> &stack, int num){

    //base case
    if (stack.empty() || stack.top() < num) {
      stack.push(num); // pushing num where it is greater than st.top()
      return;
    }

    int n = stack.top();
    stack.pop();

    //recursive call
    sortedInsert(stack, num);

    //while returning
    stack.push(n);
}
stack<int> sortStack(stack<int> &stack)
{

	//base case
    if(stack.empty())
        return stack;

    int num = stack.top();
    stack.pop();

    //recursive call
   sortStack(stack);

    //while returning back, insert the element at its sorted place
    sortedInsert(stack, num);

    return stack;

}

//TC - O(n^2)
//SC - O(N)
