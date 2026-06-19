class Solution {
public:
    long long minEnd(int n, int x) {
        //starting element would always be x itself
        long long shifted_n = n - 1;
        long long ans = x;

        for (int i = 0; i < 62; i++) {
            // Check if the i-th bit of x is 0 (a free slot)
            if (((ans >> i) & 1) == 0) {
                // Take the lowest bit of shifted_n and place it at position i
                long long bit_to_add = shifted_n & 1;
                ans |= (bit_to_add << i);
                
                // Shift shifted_n to process its next bit in the next free slot
                shifted_n >>= 1;
            }
            
            // If we've run out of bits in shifted_n, we can stop early!
            if (shifted_n == 0) break;
        }
        return ans;
    }
};