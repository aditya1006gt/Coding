class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pmax(n,-1);
        pmax[0]=nums[0];
        for(int i=1;i<n;i++) {
            pmax[i]=max(pmax[i-1],nums[i]);
        }

        vector<int> smin(n,INT_MAX);
        smin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            smin[i]=min(smin[i+1],nums[i]);
        }

        vector<int> val(n);
        int ans=-1;
        for(int i=0;i<n;i++) {
            val[i]=pmax[i]-smin[i];
            if(val[i]<=k) {
                return i;
            }
        }

        // for(auto& i:val) cout<<i<<" ";
        return -1;
    }
};