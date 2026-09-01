class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int>dp(sum+1,1e9);
        dp[0]=0; 
        for (int x:nums) {
            vector<pair<int,int>> transforms;
            
            int curr=x,cost=0;
            while(curr<=sum) {
                transforms.push_back({curr, cost});
                curr *= 2;
                cost++;
            }
            
            curr=x; cost=0;
            while(curr>0) {
                curr/=2;
                cost++;
                if (curr>0) {
                    transforms.push_back({curr,cost});
                }
            }

            vector<int> next_dp=dp; 
            
            for (int j=sum;j>=0;j--) {
                for (auto& t:transforms) {
                    int val=t.first;
                    int ops=t.second;
                    
                    if(j>=val && dp[j-val]!=1e9) 
                    {
                        next_dp[j]=min(next_dp[j],dp[j-val]+ops);
                    }
                }
            }
            dp=next_dp;
        }
        return dp[sum]==1e9?-1:dp[sum];
    }
};