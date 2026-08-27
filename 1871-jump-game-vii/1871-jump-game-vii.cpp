class Solution {
public:
    bool func(const string& s, int minJump, int maxJump, int i, vector<int>& dp, int& farthest) {
        int n=s.size();
        if(i==n-1) return dp[i]=1;
        if(i>n-1) return false;
        if(dp[i]!=-1) return dp[i];

        int r=min(i+maxJump,n-1);
        int l=i+minJump;

        int start=max(l,farthest+1);
        farthest=max(farthest,r);

        if(l>r) return dp[i]=0;
        for(int j=start;j<=r;j++) {
            if(s[j]=='0') {
                if(func(s,minJump,maxJump,j,dp,farthest))
                return dp[i]=1;
            }
        }

        return dp[i]=0;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1') return false;

        int z=0,o=0;
        for(auto& i:s) {
            if(i=='1') o++;
            else z++;
        }
        long long l=n/minJump,r=l*maxJump;
        if(o==0 && l*minJump+1<=n && n<=r) return true;

        vector<int>dp(n,-1);
        int farthest=0;

        return func(s,minJump,maxJump,0,dp,farthest);
    }
};