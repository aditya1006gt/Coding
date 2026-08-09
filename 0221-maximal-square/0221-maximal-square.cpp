class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int mx=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]=='0') continue;

                int a=0,b=0,c=0,mn;
                if(i!=0) a=dp[i-1][j];
                if(j!=0) b=dp[i][j-1];
                if(j!=0 && i!=0) c=dp[i-1][j-1];
                mn=min({a,b,c});
                dp[i][j]=mn+1;
                mx=max(mx,dp[i][j]);
            }
        }
        // for(auto& i:dp) {
        //     for(auto& j:i) {
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        return mx*mx;
    }
};