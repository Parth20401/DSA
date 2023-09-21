class Solution
{
    public:
    
    void deleteElement(stack<int>&s, int sizeOfStack, int count){
        //base case
        if(count == sizeOfStack/2){
            s.pop();
            return;
        }
        
        int num = s.top();
        s.pop();
        
        //recursive call
        deleteElement(s, sizeOfStack, count + 1);
        s.push(num);
    }
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0;
        deleteElement(s, sizeOfStack, count);
    }
};
