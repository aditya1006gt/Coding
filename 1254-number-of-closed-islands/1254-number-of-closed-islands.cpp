class Solution {
public:
    int trav(vector<vector<int>>& grid, vector<vector<int>>& vis, int ti, int tj) {
        int n=grid.size(),m=grid[0].size();
        int r[]={1,-1,0,0};
        int c[]={0,0,-1,1};

        bool flag=true;

        queue<pair<int,int>>q;q.push({ti,tj});
        vis[ti][tj]=0;
        while(!q.empty()) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++) {
                int indj=j+c[k];
                int indi=i+r[k];

                if(indj<0 || indj>=m || indi<0 || indi>=n) {
                    flag=false;
                    continue;
                }

                if(vis[indi][indj]==0 || grid[indi][indj]==1) continue;

                vis[indi][indj]=0;
                q.push({indi,indj});
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0 && vis[i][j]==-1 && trav(grid,vis,i,j)) ans++;
            }
        }
        return ans;
    }
};