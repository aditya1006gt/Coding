class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>psum(n); psum[0]=nums[0];
        vector<int>ssum(n); ssum[n-1]=nums[n-1];
        for(int i=1;i<n;i++) {
            psum[i]+=psum[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--) {
            ssum[i]+=ssum[i+1]+nums[i];
        }
        long long ans=INT_MAX;

        for(int i=0;i<n;i++) {
            long long lft=i,rht=n-1-i;
            long long vall=0,valr=0;

            if(i!=0) {
                vall=(lft*nums[i]);
                vall-=psum[i-1];
            }

            if(i!=n-1) {
                valr=ssum[i+1];
                valr-=(rht*nums[i]);
            }
            // cout<<vall+valr<<" \n";
            ans=min(ans,vall+valr);
        }
        return ans;
    }
};