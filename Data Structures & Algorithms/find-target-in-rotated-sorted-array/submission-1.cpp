class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int mid;
        while(s<e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
        
            else if(nums[mid]>nums[e]){
                if(target<nums[mid] && target>=nums[s]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{ //(nums[mid]<=nums[e] and nums[m]==nums[e] only when m==e , ie. s==e==m)
                if(target>nums[mid] && target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }

        }
        return (nums[s]==target)? s : -1;
    }
};
