class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int l=0,r=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]==0) continue;

                int a=0,b=0,c=0,mn;
                if(i!=0) a=dp[i-1][j];
                if(j!=0) b=dp[i][j-1];
                if(j!=0 && i!=0) c=dp[i-1][j-1];
                mn=min({a,b,c});
                dp[i][j]=mn+1;
                r=max(r,dp[i][j]);
            }
        }
        int ans=0;
        while(l<=r) {
            int mid=(l+r)/2;

            int min_r=INT_MAX,max_r=INT_MIN;
            int min_c=INT_MAX,max_c=INT_MIN;
            bool found=false;
            
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    if(dp[i][j]>=mid) {
                        min_r=min(min_r,i);
                        max_r=max(max_r,i);
                        min_c=min(min_c,j);
                        max_c=max(max_c,j);
                    }
                }
            }

            if(max_r-min_r>=mid || max_c-min_c>=mid) {
                found=true;
            }
            if(found) {
                ans=mid*mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return ans;
    }
};