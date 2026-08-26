class Solution {
public:
    bool func(vector<int>& price, int k, int mid) {
        int n=price.size(),ans=1;
        int lstpk=price[0];
        for(int i=0;i<n;i++) {
            if(price[i]-lstpk>=mid) {
                ans++;
                lstpk=price[i];
            }
        }
        return ans>=k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(begin(price),end(price));
        int n=price.size();
        int l=0,r=price[n-1]-price[0];
        while(l<=r) {
            int mid=(l+r)/2;
            if(func(price,k,mid)) {
                l=mid+1;
            }
            else r=mid-1;
        }
        return r;
    }
};