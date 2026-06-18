class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;
        for(int i=0; i<32; i++){
            num = num << 1;
            int bit = (n&1);
            num = num | bit;
            n = n >> 1;
        }
        return num;
    }
};
