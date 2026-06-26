class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && !(newInterval[0]>intervals[i][1] || newInterval[1]<intervals[i][0])){
            int newStart=min(intervals[i][0],newInterval[0]);
            int newEnd=max(intervals[i][1],newInterval[1]);
            // newInterval={newStart,newEnd};
            newInterval[0] = newStart;
            newInterval[1] = newEnd;
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
