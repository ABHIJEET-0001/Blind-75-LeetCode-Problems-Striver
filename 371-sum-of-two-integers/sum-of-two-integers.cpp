class Solution {
public:
    int getSum(int a, int b) {

        while(b != 0) {

            // carry
            int carry = (a & b) << 1;

            // sum without carry
            a = a ^ b;

            // new carry
            b = carry;
        }

        return a;
    }
};