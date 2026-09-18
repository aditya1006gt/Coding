class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        long long sum=0;
        int ans=1e8;
        unordered_map<int,int>mpp;
        while(r<n) {
            if(mpp[nums[r]]==0) sum+=nums[r];
            mpp[nums[r]]++;

            while(sum>=k) {
                ans=min(ans,r-l+1);
                if(mpp[nums[l]]==1) {
                    sum-=nums[l];
                }
                mpp[nums[l]]--;
                l++;
            }
            r++;
        }
        return ans==1e8?-1:ans;
    }
};