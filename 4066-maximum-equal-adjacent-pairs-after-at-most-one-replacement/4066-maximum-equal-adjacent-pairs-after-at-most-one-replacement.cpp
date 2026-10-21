class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int mx_gn=0;
        int n=nums.size();
        int cnt=0;

        map<pair<int,int>,int>pair_freq;
        for(int i=0;i<n-1;i++) {
            if(nums[i]==nums[i+1]) cnt++;

            else {
                int u=min(nums[i],nums[i+1]);
                int v=max(nums[i],nums[i+1]);
                
                pair_freq[{u,v}]++;
                
                mx_gn = max(mx_gn, pair_freq[{u,v}]);
            }
        }
        return cnt+mx_gn;
    }
};