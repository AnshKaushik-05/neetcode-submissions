class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int psum[n+1];
        psum[0]=0;
        for(int i=1;i<=n;i++){
            psum[i]=psum[i-1]+nums[i-1];
        }
        int msf=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                msf=max(msf,psum[j+1]-psum[i]);
            }
        }
        return msf;
    }
};
