class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        vector<long long>psum(n,0);
        psum[0]=nums[0];
        for(int i=1;i<n;i++) psum[i]=psum[i-1]+nums[i];

        long long ttl=psum[n-1];
        int ans=0;

        for(int i=0;i<n/2;i++) {
            long long ss=(i==0)?0:psum[i-1];

            long long sum=psum[i-1+n/2]-ss;
            if(sum>ttl-sum) ans++;
        }
        for(int i=n/2;i<n;i++) {
            long long sum=psum[n-1]-psum[i-1];
            if(n-i<n/2) {
                long long req=n/2-n+i;
                sum+=psum[req-1];
            }
            if(sum>ttl-sum) ans++;
        }
        return ans;
    }
};