class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(mid != 0 && mid == x/mid)
                return mid;
            else if(mid != 0 && mid > x/mid)
                end = mid -1;
            else
                start = mid + 1;
        }
        return start - 1;
    }
};