class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        // if(n==1) return 0;
        int l=0,r=0;
        int mn=INT_MAX,mni=-1;
        for(int i=0;i<n;i++) {
            if(nums[i]>=nums[(i+1)%n]) l++;

            if(mni==-1 || nums[mni]>nums[i])
            mni=i;
        }
        for(int i=0;i<n;i++) {
            if(nums[i]<=nums[(i+1)%n]) r++;
        }
        // cout<<"l="<<l<<" r="<<r;
        if(l!=1 && r!=1) return -1;

        if(l==1) {
            return min(mni,2+n-mni);
        }
        else {
            return min(mni+2,n-mni);
        }
        return -1;
    }
};