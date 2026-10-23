class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>psum(n,0); psum[0]=arr[0];
        for(int i=1;i<n;i++) psum[i]+=psum[i-1]+arr[i];

        int ans=0;
        int e=1,o=0;
        for(int i=0;i<n;i++) {
            if(psum[i]&1) {
                ans=(ans+e)%mod;
                o++;
            } else {
                ans=(ans+o)%mod;
                e++;
            }
        }
        return ans;
    }
};