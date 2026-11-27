class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            if(i!=0 && nums[i-1]==nums[i]) continue;
            int k=nums[i];
            int l=i+1,r=n-1;
            while(r<n && l>=0 && l<r) {
                int s=k+nums[l]+nums[r];
                if(s>0) r--;
                if(s<0) l++;
                if(s==0) {
                    ans.push_back({k,nums[l],nums[r]});
                    l++;r--;

                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
            }
        }
        return ans;
    }
};