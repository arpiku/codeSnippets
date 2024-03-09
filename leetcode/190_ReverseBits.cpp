class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        int bits = 31;
        while(bits >= 0) {
            int currBit = n & 1;
            res |= (currBit << bits);
            n >>= 1;
            bits--;
        }
        return res;
    }
};
