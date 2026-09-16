class Solution {
public:
    bool func(vector<int>& nums, long long k) {
        long long ans=0;
        for(auto& i:nums) {
            ans+=(i+k-1)/k;
        }
        return ans<=(k*k);
    }
    int minimumK(vector<int>& nums) {
        int n=nums.size(),l=1,r=1e5;
        while(l<=r) {
            int mid=(l+r)/2;
            if(func(nums,mid)) {
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};