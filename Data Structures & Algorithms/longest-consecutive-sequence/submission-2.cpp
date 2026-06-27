class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>lenMp;
        int msf=0;
        for(int x : nums){
            if(lenMp[x]==0){
                int leftLen=lenMp[x-1];
                int rightLen=lenMp[x+1];
                int newLen=leftLen+1+rightLen;
                lenMp[x]=newLen;
                lenMp[x-leftLen]=newLen;
                lenMp[x+rightLen]=newLen;
                msf=max(newLen,msf);
            }
        }
        return msf;
    }
};
