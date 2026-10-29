class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans=0,n=rungs.size();
        if(rungs[0]>dist) ans+=((rungs[0]-1)/dist);
        for(int i=1;i<n;i++) {
            if(rungs[i]-rungs[i-1]<=dist) continue;

            int val=rungs[i]-rungs[i-1]-1;
            ans+=(val/dist);
        }
        return ans;
    }
};