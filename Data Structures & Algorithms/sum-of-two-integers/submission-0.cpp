class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0)
        {
            int carry = (a & b) << 1; // 110 + 011 => 110 & 011 -> 010 -> (carry hai to ek left shift)
            a = a ^ b; // 110 ^ 011 -> 101 -> addition without carry
            b = carry;
        }
        return a;
    }
};
