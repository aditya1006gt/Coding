class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX,mx=INT_MIN;
        for(int i=0;i<n;i++) {
            mn=min(mn,nums[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++) {
            ans+=abs(nums[i]-mn);
        }
        return ans;
    }
};