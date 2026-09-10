class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1) return r-l+1;
        double st=pow(l,1.0/k);
        double ed=pow(r,1.0/k);
        // cout<<"st="<<st<<" ed="<<ed<<"\n";
        int ans=0;
        for(int i=max(st-1,0.0);i<=ed+1;i++) {
            long long val=pow(i,k);
            // cout<<"i="<<i<<" sq="<<val<<" \n";
            if(l<=val && val<=r) ans++;
        }
        return ans;
    }
};