class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        vector<int> min_len(n, INT_MAX);
        mpp[0]=-1;
        int v=INT_MAX;
        int ans=INT_MAX;
        int s=0;
        for(int i=0;i<n;i++) {
            s+=arr[i];
            if(mpp.find(s-target)!=mpp.end()) {
                int ind=mpp[s-target];
                int l=i-ind;

                if(ind>=0 && min_len[ind]!=INT_MAX) {
                    ans=min(ans,l+min_len[ind]);
                }
                v=min(v,l);
            }
            min_len[i]=v;
            mpp[s]=i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};