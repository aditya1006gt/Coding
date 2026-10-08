class Solution {
public:
    int asc_rot(vector<int>& nums) {
        int n=nums.size(),c=0;
        for(int i=0;i<n;i++) {
            c=i;
            if(nums[i]==0) return i;
        }
        return c;
    }
    int desc_rot(vector<int>& nums) {
        int n=nums.size(),c=0;
        for(int i=0;i<n;i++) {
            c=i;
            if(nums[i]==n-1) return i+1;
        }
        return c;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size(),c=0;
        if(n==1) return 0;
        for(int i=0;i<n;i++) {
            if(i!=0 && nums[i-1]>nums[i]) c++;
            if(i==0 && nums[n-1]>nums[0]) c++;
        }
        int ms=INT_MAX;
        if(c==1) ms=min(ms,asc_rot(nums));
        else if(c==n-1) ms=min(ms,desc_rot(nums));
        else return -1;

        reverse(nums.begin(),nums.end());
        c=0;
        for(int i=0;i<n;i++) {
            if(i!=0 && nums[i-1]>nums[i]) c++;
            if(i==0 && nums[n-1]>nums[0]) c++;
        }
        if(c==1) ms=min(ms,asc_rot(nums) +1 );
        else if(c==n-1) ms=min(ms,desc_rot(nums) + 1);
        return ms;
    }
};