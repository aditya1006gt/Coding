class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int mod=1e9+7;
        int r=k,n=nums.size(),cost=1;
        long long ans=0;
        for(int i=0;i<n;i++) {
            if(nums[i]<=r) {
                r-=nums[i];
                continue;
            }

            int rem=nums[i]-r;
            int d=rem/k;d+=(rem%k!=0)?1:0;
            r+=(d*k)-nums[i];
            ans+=d;
        }

        long long a=ans,b=ans+1;
        if(ans%2==0) a/=2;
        else b/=2;
        long long val=((a%mod)*(b%mod))%mod;
        return val;
    }
};