class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxVal=INT_MIN;
        for(auto& v : intervals){
            maxVal=max(maxVal,v[0]);
        }

        vector<int>startEnd(maxVal+1,-1);
        for(auto& v : intervals){
            startEnd[v[0]]=max(v[1],startEnd[v[0]]);
        }

        vector<vector<int>>ans;
        int overLap=-1;
        int start;
        for(int i=0;i<=maxVal;i++){
            if(startEnd[i]!=-1){
                if(overLap>=i){
                    overLap=max(overLap,startEnd[i]);
                }
                else{
                    if(overLap!=-1 && overLap<i) ans.push_back({start,overLap});
                    start=i;
                    overLap=startEnd[i];
                }
            }
        }
        ans.push_back({start,overLap});
        return ans;
    }
};
