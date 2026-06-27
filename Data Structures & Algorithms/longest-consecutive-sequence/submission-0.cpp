class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool>freqMap;

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
            if(p.second==true){
                msf=max(msf,len);
                len=1;
            }else{
                len++;
            }
        }
        msf=max(msf,len);
        return msf;
    }
};
