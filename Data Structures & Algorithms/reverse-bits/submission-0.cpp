class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return rev(n, 32);
    }

private:
    uint32_t rev(uint32_t n, int bits) {
        if (bits == 1) return n & 1;

        int half = bits / 2;
        uint32_t left  = n >> half;
        uint32_t right = n & ((1u << half) - 1);

        return (rev(right, half) << half) | rev(left, half);
    }
};