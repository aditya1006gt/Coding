class Solution {
public:
    int countArrays(vector<int>& ori, vector<vector<int>>& bounds) {
        int n=ori.size();
        
        int mnd=INT_MIN; 
        int mxd=INT_MAX;
        
        for (int i=0;i<n;i++) {
            int cmnd=bounds[i][0]-ori[i];
            int cmxd=bounds[i][1]-ori[i];
            
            mnd=max(mnd,cmnd);
            mxd=min(mxd,cmxd);
        }
        return max(0,mxd-mnd+1);
    }
};