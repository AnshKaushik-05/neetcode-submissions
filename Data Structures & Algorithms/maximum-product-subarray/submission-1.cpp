class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int x=nums[0];
        int msf=x;
        for(int i=1;i<n;i++){
            x=max(x*nums[i],nums[i]);
            msf=max(x,msf);
        }

        int product=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) product=1;
            else{
                product*=nums[i];
                msf=max(product,msf);
            }
        }
        product=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0) product=1;
            else{
                product*=nums[i];
                msf=max(product,msf);
            }
        }
        
        return msf;
    }
};