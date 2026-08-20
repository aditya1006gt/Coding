class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        int c=0;
        while(r<n-1) {
            int f=0;
            for(int i=l;i<=r;i++) {
                f=max(f,nums[i]+i);
            }
            c++;
            l=r+1;
            r=f;
        }
        return c;
    }
};