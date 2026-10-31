class Solution {
public:
    pair<int,int> calc(vector<vector<int>>& grid, int i,int j, char dir) {
        int m=grid.size(),n=grid[0].size();
        if(i>=m || j>=n) return {-1,-1};
        if(grid[i][j]==1) {
            if(dir=='R') {
                return calc(grid,i+1,j,'D');
            } else {
                return calc(grid,i,j+1,'R');
            }
        }
        return {i,j};
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int mod=1e9+7;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++) {
            if(i==0) dp[0][i]=1;
            else {
                if(grid[0][i]==1) {
                    auto [p1,p2]=calc(grid,0,i,'R');

                    if(p1==-1 || p2==-1) break;
                    dp[p1][p2]=1;

                    break;
                } else {
                    dp[0][i]=1;
                }
            }
        }

        for(int i=1;i<m;i++) {
            for(int j=0;j<n;j++) {
                int vall=0,valu=0;
                if(j!=0) vall=dp[i][j-1];
                valu=dp[i-1][j];
                
                if(grid[i][j]==1) {
                    auto [p1,p2]=calc(grid,i,j,'R');

                    if(p1!=-1 && p2!=-1) {
                        dp[p1][p2]=(dp[p1][p2]+vall)%mod;
                    }

                    auto [p3,p4]=calc(grid,i,j,'D');
                    if(p3!=-1 && p4!=-1) {
                        dp[p3][p4]=(dp[p3][p4]+valu)%mod;
                    }
                } else {
                    dp[i][j]=(dp[i][j]+vall+valu)%mod;
                }
            }
        }

        return dp[m-1][n-1];
    }
};