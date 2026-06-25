class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num=0;
        int j=31;
        for(int i=0;i<=31;i++){
            if((n>>i)&1){
                num=num|(1u<<j);
            }
            j--;
        }
        return num;
    }
};
