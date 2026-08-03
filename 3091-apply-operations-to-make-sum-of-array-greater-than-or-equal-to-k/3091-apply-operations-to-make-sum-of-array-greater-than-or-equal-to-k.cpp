class Solution {
public:
    int minOperations(int k) {
        int ans=k;
        if(k==1) return 0;
        for(int i=1;i<=k;i++) {
            int c=i-1;
            int d=(k+i-1)/i -1;
            ans=min(c+d,ans);
        }
        return ans;
    }
};