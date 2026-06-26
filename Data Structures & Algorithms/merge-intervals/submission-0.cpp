class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i==n-1 || intervals[i][1]<intervals[i+1][0]) ans.push_back(intervals[i]);
            else{
                intervals[i+1][0]=min(intervals[i][0],intervals[i+1][0]); //OR intervals[i+1][0]=intervals[i][0] , since the array is sorted
                intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
            }
        }
        return ans;
    }
};
