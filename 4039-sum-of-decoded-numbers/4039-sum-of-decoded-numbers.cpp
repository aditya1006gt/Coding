class Solution {
public:
    int mod=1e9+7;
    long long power(long long& x, long long& y) {
        long long ans=1;
        x%=mod;
        while(y>0) {
            if(y%2==1) {
                ans=(ans*x)%mod;
            } 
            x=(x*x)%mod;
            y/=2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++) {
            long long num=nums[i];
            long long width=num%10;
            long long d=num/10;
            // cout<<"width="<<width<<" d="<<d<<" ";
            int s=log10(d)+1;
            // cout<<"s="<<s<<" ";

            long long p=(long long)pow(10,s-width);

            long long x=d/p,y=d%p;
            // cout<<"x="<<x<<" y="<<y<<" ";

            int pw=power(x,y);
            ans=(ans+pw)%mod;
            // cout<<"\n";
        }
        return ans;
    }
};