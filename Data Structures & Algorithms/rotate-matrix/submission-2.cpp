class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        int lb=0,ub=n-1;
        int i=0;
        while(lb<=ub){
            for(int j=lb;j<ub;j++){
                swap(matrix[i][j],matrix[n-1-j][i]);
                swap(matrix[n-1-j][i],matrix[n-1-i][n-1-j]);
                swap(matrix[n-1-i][n-1-j],matrix[j][n-1-i]);
            }
            i++;
            lb++;
            ub--;
        }
    }
};
