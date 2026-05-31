class MedianFinder {
    using minHeap = priority_queue<int, vector<int>, greater<int>>;
    vector<int> nums; minHeap right; priority_queue<int> left; int size = 0;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        size ++;
        int l = left.size(), r = right.size();
        if(l == 0 && r == 0){
            left.push(num); return;
        }
        if(l == r){
            if(num > right.top()){
                left.push(right.top());
                right.pop();
                right.push(num); return;
            }
            else{
                left.push(num); return;
            }
        }
        else if(l > r){
            if(num <= left.top()){
                right.push(left.top());
                left.pop();
                left.push(num); return;
            }
            else{
                right.push(num); return;
            }
        }
        else{
            if(num > right.top()){
                left.push(right.top());
                right.pop();
                right.push(num); return;
            }
            else{
                left.push(num); return;
            }
        }
    }
    
    double findMedian() {
        double maxL = left.top();
        if(size%2 == 0){
            double minR = right.top();
            return (double)(maxL + minR)/2;
        }
        else return maxL;
    }
};
