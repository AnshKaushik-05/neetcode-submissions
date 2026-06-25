class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n=intervals.size();
        for(int i=n-1;i>0;i--){
            if(intervals[i][0]<intervals[i-1][0]){
                swap(intervals[i],intervals[i-1]);
            }
        }
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(i==n-1 || intervals[i][1]<intervals[i+1][0]) ans.push_back(intervals[i]);
            else{
                intervals[i+1]={intervals[i][0],max(intervals[i][1],intervals[i+1][1])};
            }
        }
        return ans;
    }
};
