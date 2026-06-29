class Solution {
public:
    int f(vector<int>&nums,int n,int s){
        int b=0;
        int a=0;
        for(int i=n-1;i>=s;i--){
            int c=max(a,nums[i]+b);
            b=a;
            a=c;
        }
        return a;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(f(nums,n-1,0),f(nums,n,1));
    }
};
