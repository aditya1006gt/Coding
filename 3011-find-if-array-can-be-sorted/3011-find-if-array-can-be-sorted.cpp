class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(__builtin_popcount(nums[i])==__builtin_popcount(nums[j])) {
                    if(nums[i]>=nums[j]) swap(nums[i],nums[j]);
                    // else break;
                }
                else break;
            }
        }
        // for(auto& i:nums) {
        //     cout<<"i="<<i<<" bit="<<__builtin_popcount(i)<<"\n";
        // }
        for(int i=1;i<n;i++) {
            if(nums[i-1]>nums[i]) return 0;
        }

        return 1;
    }
};