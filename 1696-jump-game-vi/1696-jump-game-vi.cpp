class Solution {
public:
    // int func(vector<int>& nums, int k, int i, vector<int>& dp) {
    //     if(i<0) return 0;
    //     if(i==0) {
    //         return nums[0];
    //     }
    //     if(dp[i]!=-1) return dp[i];
    //     int ans=INT_MIN;
    //     for(int j=1;j<=k;j++) {
    //         int ind=i-j;
    //         if(ind<0) break;
    //         int val=func(nums,k,ind,dp);
    //         ans=max(ans,val+nums[i]);
    //     }
    //     return dp[i]=ans;
    // }
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,-1);
        multiset<int> s({dp[0]=nums[0]});
        for(int i=1;i<n;i++) {
            if(i>k) {
                s.erase(s.find(dp[i-k-1]));
            }
            dp[i]=*rbegin(s)+nums[i];
            s.insert(dp[i]);
        }
        return dp[n-1];
    }
};