class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int si=1,sd=1;
        for(int i=1;i<n;i++) {
            if(nums[i-1]<nums[i]) {
                si++;sd=1;
            }
            else if(nums[i-1]>nums[i]) {
                sd++;si=1;
            } 
            else {
                sd=1;si=1;
            }
            ans=max({ans,sd,si});
        }
        return ans;
    }
};