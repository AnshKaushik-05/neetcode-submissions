class Solution {
public:
    int f(vector<int>&nums,int n){
        int b=0;
        int a=0;
        int c;
        for(int i=n-1;i>=0;i--){
            c=max(a,nums[i]+b);
            b=a;
            a=c;
        }
        return c;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        return f(nums,n);
    }
};
