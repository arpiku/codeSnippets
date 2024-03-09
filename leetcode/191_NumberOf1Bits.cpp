class Solution {
public:
    uint8_t hammingWeight(uint32_t n) {
        if(!n)
            return 0;
        uint8_t count = 0;
        while(n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};
