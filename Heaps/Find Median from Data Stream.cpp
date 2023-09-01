class MedianFinder {
private:
    // Max heap of lower values & min heap of higher values, access to mids
    priority_queue<int> lower;//lower heap
    priority_queue<int, vector<int>, greater<int>> upper;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //insert the new element directly into lower heap
        if(lower.empty()){
            lower.push(num);
            return;
        }

        if(lower.size() > upper.size()){
            //if lower heap has a larger element so we will tranfer that element into upper heap
            if(lower.top() > num){
                upper.push(lower.top());
                lower.pop();
                lower.push(num);
            }
            else{
                upper.push(num);
            }
        }
        else{
            if(num > upper.top()){
                lower.push(upper.top());
                upper.pop();
                upper.push(num);
            }
            else{
                lower.push(num);
            }
        }
    }
    
    double findMedian() {
        double result = 0.0;

        //if len is odd
        if(lower.size() == upper.size())
            result = lower.top() + (upper.top() - lower.top()) / 2.0;

        //if len is even
        else{
            if(lower.size() > upper.size())
                result = lower.top();
            else
                result = upper.top();
        }

        return result;
    }
};

//Time: O(log n) + O(1)
//Space: O(n)

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
