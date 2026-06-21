class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        
        int msf=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=max(sum+nums[i],nums[i]); //maximum subarray sum ending at index i
            msf=max(msf,sum); //maximum subarray sum found so far
        }
        return msf;
    }
};
