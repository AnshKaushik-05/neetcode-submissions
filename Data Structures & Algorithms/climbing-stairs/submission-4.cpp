class Solution {
public:
    int f(int n) {
        int a=1;
        int b=1;
        int c;
        for(int i=2;i<n+1;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }

    int climbStairs(int n) {
        if(n<=1)return 1;
        return f(n);
    }
};
