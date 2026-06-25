class Solution {
public:
    int getSum(int a, int b) {
        while(true){
            int sumWithoutCarry=a^b;
            int shiftCarry=(a&b)<<1;
            if(shiftCarry==0){
                return sumWithoutCarry;
            }
            a=sumWithoutCarry;
            b=shiftCarry;
        }
    }
};
