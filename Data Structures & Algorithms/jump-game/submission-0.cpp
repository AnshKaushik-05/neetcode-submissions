class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int farthestReach=0;
        for(int i=0;i<n;i++){
            if(i<=farthestReach){
                farthestReach=max(farthestReach,i+nums[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};
