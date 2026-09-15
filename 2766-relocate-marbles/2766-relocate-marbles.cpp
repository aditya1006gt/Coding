class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int>mpp;
        for(auto& i:nums) mpp[i]++;

        int n=moveFrom.size();
        for(int i=0;i<n;i++) {
            int l=mpp[moveFrom[i]];
            mpp.erase(moveFrom[i]);
            mpp[moveTo[i]]=l;
        }
        vector<int> ans;
        for(auto& i:mpp) {
            if(i.second!=0) ans.push_back(i.first);
        }
        return ans;
    }
};