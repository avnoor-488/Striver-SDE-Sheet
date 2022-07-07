class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>small;
    priority_queue<int>large;
    
    void addNum(int num) {
        large.push(num);
        small.push(large.top());
        large.pop();
        
        if(large.size()<small.size())
        {    
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        
        if(large.size()>small.size())
            return large.top();
        else 
            return (small.top()+large.top())/2.0;
        
       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
