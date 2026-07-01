class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int msf=nums[0];;
    
        int minEndingHere=nums[0];
        int maxEndingHere=nums[0];

        for(int i=1;i<n;i++){
            int prevMin=minEndingHere;
            int prevMax=maxEndingHere;
            minEndingHere=min(nums[i],min(prevMin*nums[i],prevMax*nums[i]));
            maxEndingHere=max(nums[i],max(prevMin*nums[i],prevMax*nums[i]));
            msf=max(msf,maxEndingHere);
        }
        return msf;
    }
};
