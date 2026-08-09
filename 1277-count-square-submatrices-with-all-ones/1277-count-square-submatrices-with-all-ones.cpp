class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int mx=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==0) continue;

                int a=0,b=0,c=0,mn;
                if(i!=0) a=dp[i-1][j];
                if(j!=0) b=dp[i][j-1];
                if(j!=0 && i!=0) c=dp[i-1][j-1];
                mn=min({a,b,c});
                dp[i][j]=mn+1;
                mx=max(mx,dp[i][j]);
            }
        }
        for(auto& i:dp) {
            for(auto& j:i) {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        vector<int> arr(max(m,n)+1);
        for(auto& i:dp) {
            for(auto& j:i) {
                if(j!=0)
                arr[j]++;
            }
        }

        cout<<"\n";
        int x=0;
        for(auto& i:arr) {
            cout<<x<<"="<<i<<" ";
            x++;
        }
        cout<<"\n";

        int p=-1;
        for(int i=max(m,n);i>=0;i--) {
            if(arr[i]==0) continue;

            if(p!=-1) arr[i]+=arr[p];
            p=i;
        }
        int ans=0;
        for(int i=max(m,n);i>=0;i--) {
            if(arr[i]==0) continue;

            ans+=arr[i];
        }
        return ans;
    }
};