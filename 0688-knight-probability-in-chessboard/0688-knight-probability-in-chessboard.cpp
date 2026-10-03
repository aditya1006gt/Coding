class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>>dp(n,vector<double>(n,0.0));
        dp[row][column]=1.0;
        int trav[][2]={
            {2,1},{2,-1},{-2,1},{-2,-1},
            {1,2},{1,-2},{-1,2},{-1,-2}
        };
        
        for (int step=0;step<k;step++) {
            vector<vector<double>>next_dp(n, vector<double>(n,0.0));
            
            for (int r=0;r<n;r++) {
                for (int c=0;c<n;c++) {
                    
                    if (dp[r][c]>0) {
                        for (auto& [dr,dc] : trav) {
                            int nr=r+dr;
                            int nc=c+dc;
                            
                            if (nr>=0 && nr<n && nc>=0 && nc<n) {
                                next_dp[nr][nc]+=dp[r][c]/8.0;
                            }
                        }
                    }
                    
                }
            }
            dp=next_dp; 
        }
        
        double p=0.0;
        for(int r=0;r<n;r++) {
            for(int c=0;c<n;c++) {
                p+=dp[r][c];
            }
        }
        
        return p;
    }
};