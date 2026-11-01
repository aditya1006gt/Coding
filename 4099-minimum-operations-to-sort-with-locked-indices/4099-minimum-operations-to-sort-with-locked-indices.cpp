class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size();
        int ans=0,cnt=0;
        
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<n-1-i;j++) {
                if(nums[j]>nums[j+1]) {
                    if(locked[nums[j]-1]==1) {
                        cnt++;
                        locked[nums[j]-1]=0;
                    }
                    if(locked[nums[j+1]-1]==1) {
                        cnt++;
                        locked[nums[j+1]-1]=0;
                    }
                    swap(nums[j],nums[j+1]);
                    ans++;
                }
            }
        }
        if(cnt>k) return -1;
        return ans+cnt;
    }
};