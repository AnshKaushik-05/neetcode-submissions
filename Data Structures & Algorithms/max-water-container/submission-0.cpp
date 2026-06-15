class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int mwsf=0; //area cannot be negative

        int i=0,j=n-1;
        while(i<j){
            int height=min(heights[i],heights[j]);
            int width=(j-i);
            mwsf=max(mwsf,height*width);

            if(heights[i]>heights[j]){
                j--;
            }
            else{ //(heights[i]<=heights[j])
                i++;
            } 
        }
        return mwsf;
    }
};
