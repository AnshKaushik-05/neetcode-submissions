class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>freqMap;

        for(int x : nums){
            if(freqMap.find(x-1)!=freqMap.end()){
                freqMap[x]=false;
            }else{
                freqMap[x]=true;
            }
            
            if(freqMap.find(x+1)!=freqMap.end()){
                freqMap[x+1]=false;
            }
        }

        int msf=0;
        int len=0;
        for(auto& p : freqMap){
            int el=p.first;
            int start=p.second;
            if(start){
                int cnt=0;
                while(freqMap.find(el)!=freqMap.end()){
                    cnt++;
                    el++;
                }
                msf=max(msf,cnt);
            }
        }
        return msf;
    }
};
