class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int>ans;
        int lbi=0,lbj=0,ubi=m-1,ubj=n-1;
        int i=0,j=0;
        while(lbi<=ubi && lbj<=ubj){
            for(j=lbj,i=lbi;j<=ubj;j++){
                ans.push_back(matrix[i][j]);
            }
            lbi++;
            if(lbi>ubi)break;

            for(i=lbi,j=ubj;i<=ubi;i++){
                ans.push_back(matrix[i][j]);
            }
            ubj--;
            if(ubj<lbj)break;

            for(i=ubi,j=ubj;j>=lbj;j--){
                ans.push_back(matrix[i][j]);
            }
            ubi--;
            if(ubi<lbi)break;

            for(i=ubi,j=lbj;i>=lbi;i--){
                ans.push_back(matrix[i][j]);
            }
            lbj++;
        }
        return ans;
    }
};
