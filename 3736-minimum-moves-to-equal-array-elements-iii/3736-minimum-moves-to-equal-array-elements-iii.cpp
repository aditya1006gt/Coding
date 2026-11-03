class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>psum(n); psum[0]=nums[0];
        for(int i=1;i<n;i++) {
            psum[i]+=psum[i-1]+nums[i];
        }
        long long ans=0;

        for(int i=0;i<n;i++) {
            if(nums[i]==nums[n-1]) {
                return (i*nums[n-1])-(psum[i]-nums[i]);
            }
        }
        return -1;
    }
};