class Solution {
public:
    int f(vector<int>&nums){
        int n=nums.size();
        vector<int>next(n+1);
        for(int j=0;j<=n;j++){
            next[j]=0;
        }

        for(int i=n-1;i>=0;i--){
            vector<int>cur(n+1);
            for(int j=-1;j<i;j++){
                int insert=0;
                if(j==-1 || nums[j]<nums[i]){
                    insert=1+next[i+1];
                }
                int donotInsert=next[j+1];
                cur[j+1]=max(insert,donotInsert);
            }
            next=cur;
        }
        return next[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        return f(nums);
    }
};
