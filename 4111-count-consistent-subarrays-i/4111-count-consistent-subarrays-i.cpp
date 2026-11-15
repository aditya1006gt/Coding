class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++) {
            int val=nums[i];
            int mn=nums[i];
            for(int j=i+1;j<n;j++) {
                val=(val&nums[j]);
                mn=min(mn,nums[j]);
                if(val==mn) ans++;
            }
        }
        return ans;
    }
};