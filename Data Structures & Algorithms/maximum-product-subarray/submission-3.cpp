class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int msf=INT_MIN;

        int productPrefix=1;
        int productSuffix=1;
        for(int i=0;i<n;i++){
            productPrefix=nums[i]*(productPrefix==0 ? 1 : productPrefix);
            productSuffix=nums[n-1-i]*(productSuffix==0 ? 1 : productSuffix);
            msf=max(msf,max(productPrefix,productSuffix));
        }
        return msf;
    }
};