class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0)); vis[0][0]=1;
        int ansi=0,ansj=0;
        while(true) {
            int l=0,r=0;
            if(grid[ansi][ansj]=='L') r=-1;
            else if(grid[ansi][ansj]=='R') r=1;
            else if(grid[ansi][ansj]=='D') l=1;
            else if(grid[ansi][ansj]=='U') l=-1;

            if(ansi+l<m && ansi+l>=0 && ansj+r<n && ansj+r>=0 && vis[ansi+l][ansj+r]==0) {
                vis[ansi+l][ansj+r]=1;
                ansi+=l;
                ansj+=r;
            }
            else break;
        }
        return {ansi,ansj};
    }
};