class Solution {
public:
    int minDistance(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n2;i++) dp[0][i]=i;
        for(int i=0;i<=n1;i++) dp[i][0]=i;

        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                {
                    int a=1+/*replace*/dp[i-1][j-1];
                    int b=1+/*insert*/dp[i][j-1];
                    int c=1+/*delete*/dp[i-1][j];
                    dp[i][j]=min({a, b, c});
                }
            }
        }
        return dp[n1][n2]; 
    }
};




/*

    int minDistance(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return fun(text1,text2,n1,n2,dp); 
    }
    int fun(const string& text1,const string& text2,int i1,int i2,vector<vector<int>>& dp)
    {
        if(i1==0) return i2;
        if(i2==0) return i1;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(text1[i1-1]==text2[i2-1]) return dp[i1][i2]=fun(text1,text2,i1-1,i2-1,dp);

        int a=1+fun(text1,text2,i1-1,i2-1,dp);//replace
        int b=1+fun(text1,text2,i1,i2-1,dp);//insert
        int c=1+fun(text1,text2,i1-1,i2,dp);//delete
        return dp[i1][i2]=min({a, b, c});
    }

*/


/*

    int minDistance(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return fun(text1,text2,n1-1,n2-1,dp); 
    }
    int fun(const string& text1,const string& text2,int i1,int i2,vector<vector<int>>& dp)
    {
        if(i1<0) return i2+1;
        if(i2<0) return i1+1;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(text1[i1]==text2[i2]) return dp[i1][i2]=fun(text1,text2,i1-1,i2-1,dp);

        int a=1+fun(text1,text2,i1-1,i2-1,dp);//replace
        int b=1+fun(text1,text2,i1,i2-1,dp);//insert
        int c=1+fun(text1,text2,i1-1,i2,dp);//delete
        return dp[i1][i2]=min({a, b, c});
    }

*/
