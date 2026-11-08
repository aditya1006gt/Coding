class Solution {
public:
    int func(vector<vector<int>>& grid, int r, int c) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++) {
            if(i==r) continue;

            if(grid[i][c]==1) return 1;
        }
        for(int i=0;i<n;i++) {
            if(i==c) continue;

            if(grid[r][i]==1) return 1;
        }
        return 0;
    }
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        
        int ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1 && func(grid,i,j)) ans++;
            }
        }
        return ans;
    }
};