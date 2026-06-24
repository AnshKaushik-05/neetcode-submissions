class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0]=0;
        int x;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                //some way to determine x
                x=i;
                ans[i]=1;
            }else{
                ans[i]=ans[i-x]+1;
            }
        }
        return ans;
    }
};
