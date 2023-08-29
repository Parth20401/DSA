int sum(vector<int> &A){
    int sumOfArray = 0;
    for(int i=0; i<A.size(); i++){
        sumOfArray += A[i];
    }
    return sumOfArray;
}

int getStudents(vector<int> &A, int pages){
    int students = 1;
    long long pageStudents = 0;
    
    for(int i=0; i<A.size(); i++){
        if(pageStudents + A[i] <= pages){
            pageStudents += A[i];
        }
        else{ //if true, means we have to get new student
            students++;
            pageStudents = A[i];//allocate pages for next pages
        }
    }
    return students;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size())    return -1;
    
    int low = *max_element(A.begin(), A.end()); //STL to give max max_element of array
    int high = sum(A);//sum of array
    
    while(low <= high){
        int mid = low + (high - low)/2;
        int students = getStudents(A, mid); //get the no of students with allocated pages i.e., mid
        if(students > B)
            low = mid + 1;//if students come out to be more, than move ahead with more pages
        else
            high = mid - 1;
    }
    return low;
}
//TC - O((log(sum(arr) - max(arr)) + 1) * n)
//SC - O(1)
