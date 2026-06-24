class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int x=i;
            int num=0;
            while(x>0){
                x=x&(x-1);
                num++;
            }
            ans.push_back(num);
        }
        return ans;
    }
};
