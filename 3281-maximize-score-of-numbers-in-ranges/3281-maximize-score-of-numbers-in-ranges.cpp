class Solution {
public:
    bool func(vector<int>& start, int mid, int d) {
        int n=start.size();
        long long p=start[0];
        for (int i=1;i<start.size();++i) {
            long long val=p+mid;
            
            if(val>(long long)start[i]+d) {
                return false; 
            }
            p=max((long long)start[i],val);
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int n=start.size(),l=0,r=2*1e9;
        int ans=0;
        while(l<=r) {
            int mid=r-(r-l)/2;
            if(func(start,mid,d)) {
                l=mid+1;
                ans=mid;
            } else {
                r=mid-1;
            }
        }
        return ans;
    }
};