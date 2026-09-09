class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>arr(n,0);
        for(int i=0;i<n;i++) {
            int l=max(0,i-lights[i]);
            int r=min(n-1,lights[i]+i);
            if(l==r && lights[i]==0) continue;

            arr[l]+=1;
            if(r!=n-1) arr[r+1]-=1;
        }
        double ans=0,temp=0;
        int s=0;
        for(auto& i:arr) {
            s+=i;
            if(s==0) temp++;
            else if(s>0 && temp!=0) {
                ans+=ceil(temp/3.0);
                temp=0;
            }
        }
        if(temp) ans+=ceil(temp/3.0);
        return ans;
    }
};