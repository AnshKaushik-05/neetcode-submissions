class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int msf=INT_MIN;

        int product=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                msf=max(msf,0);
                product=1;
            } 
            else{
                product*=nums[i];
                msf=max(product,msf);
            }
        }
        product=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                msf=max(msf,0);
                product=1;
            } 
            else{
                product*=nums[i];
                msf=max(product,msf);
            }
        }
        
        return msf;
    }
};