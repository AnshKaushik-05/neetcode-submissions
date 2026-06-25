class Solution {
public:
    int getSum(int a, int b) {
        int sum=0;
        int carry=0;
        for(int i=0;i<=31;i++){
            int bitA=(a>>i)&1;
            int bitB=(b>>i)&1;

            // int bit;
            // if(carry==1){
            //     bit=bitA^bitB^carry;
            // }else{
            //     bit=bitA^bitB;
            // }

            int bit=bitA^bitB^carry;
            sum=sum|(bit<<i);

            if((bitA && bitB) || (bitA && !bitB && carry) || (!bitA && bitB && carry) ) carry=1;
            else carry=0;
        }
        return sum;
    }
};
