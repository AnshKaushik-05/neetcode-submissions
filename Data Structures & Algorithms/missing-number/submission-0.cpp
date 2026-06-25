class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int missingNum=0;
        for(int i=0;i<=n;i++){
            missingNum=missingNum^i;
        }
        for(int x : nums){
            missingNum=missingNum^x;
        }
        return missingNum;
    }
};
