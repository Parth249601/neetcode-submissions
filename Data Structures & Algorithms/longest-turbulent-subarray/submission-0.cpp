class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        
        int max_len = 1;
        int curr_len = 1;
        
        // Track the previous direction: 1 for UP, -1 for DOWN, 0 for EQUAL
        int last_sign = 0; 
        
        for (int i = 1; i < n; i++) {
            // 1. Figure out the current direction
            int curr_sign = 0;
            if (arr[i] > arr[i - 1]) curr_sign = 1;
            else if (arr[i] < arr[i - 1]) curr_sign = -1;
            
            // 2. Apply our state machine rules
            if (curr_sign == 0) {
                // HARD RESET: Elements are equal, streak destroyed.
                curr_len = 1;
            } 
            else if (curr_sign == -last_sign) {
                // GOOD: Signs alternated perfectly!
                curr_len++;
            } 
            else {
                // SOFT RESET: Signs repeated (e.g., UP then UP).
                // The current and previous elements still form a valid pair of 2.
                curr_len = 2;
            }
            
            // 3. Update globals and memory for the next loop
            max_len = max(max_len, curr_len);
            last_sign = curr_sign;
        }
        
        return max_len;
    }
};