class Solution {
public:
    // long long solve(vector<int>& nums, vector<int>& colors, int i) {
    //     if(i<0) return 0;
    //     if(memo[i]!=-1) return memo[i];
        
    //     long long skip=solve(nums,colors,i-1);

    //     long long rob=nums[i];
    //     if (i>0) {
    //         if (colors[i]==colors[i-1]) rob+=solve(nums,colors,i-2);
    //         else rob+=solve(nums,colors,i-1);
    //     }
        
    //     return memo[i] = max(skip, rob);
    // }
    vector<long long>memo;
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        // memo.assign(n,-1);
        // return solve(nums, colors, n - 1);

        vector<long long>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++) {
            long long rob=nums[i];
            long long skip=dp[i-1];

            long long l=0,r=0;
            if (colors[i]==colors[i-1]) {
                if(i>1) l=dp[i-2];
            }
            else r=dp[i-1];
            rob+=max(l,r);

            dp[i]=max(rob,skip);
        }

        return dp[n-1];
    }
};