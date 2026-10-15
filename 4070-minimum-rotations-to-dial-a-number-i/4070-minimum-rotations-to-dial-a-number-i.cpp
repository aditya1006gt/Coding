class Solution {
public:
    int minRotations(string s) {
        int val=s[0]-'0',n=s.size(),pvs=s[0]-'0';
        int ans=min(val,10-val);
        // cout<<"1 0 "<<s[0]<<"\n";
        for(int i=1;i<n;i++) {
            // cout<<i+1<<" "<<pvs<<" "<<s[i]<<"\n";
            
            val=abs((s[i]-'0')-pvs);
            ans+=min(val,10-val);
            pvs=s[i]-'0';

        }
        return ans;
    }
};