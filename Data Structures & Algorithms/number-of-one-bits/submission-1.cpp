class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num=0;
        for(int i=0;i<=31;i++){
            if((n>>i)&1){
                num++;
            }
        }
        return num;
    }
};
