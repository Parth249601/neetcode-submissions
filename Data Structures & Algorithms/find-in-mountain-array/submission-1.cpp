/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &arr, int target, int lo, int hi, bool ascending) {
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int val_mid = arr.get(mid);
            if(val_mid == target)
                return mid;
            else if(val_mid > target && ascending || (val_mid < target && !ascending))
                hi = mid -1;
            else
                lo = mid + 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int size= mountainArr.length();
        int start = 0, end = size - 1;
        //find the peak index
        while(start < end){
            int mid = start + (end - start)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                start = mid + 1;
            else 
                end = mid;
        }

        int peak = start;
        int idx = binarySearch(mountainArr, target, 0, peak, true);
        if (idx != -1) return idx;

        // 3. Binary search descending half
        return binarySearch(mountainArr, target, peak + 1, size - 1, false);
    }
};