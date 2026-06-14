class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffixArr(n);
        suffixArr[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suffixArr[i]=suffixArr[i+1]*nums[i+1];
        }

        int prefixProduct=1;
        vector<int>output(n);
        for(int i=0;i<n;i++){
            output[i]=prefixProduct*suffixArr[i];
            prefixProduct*=nums[i];
        }
        return output;
    }
};
