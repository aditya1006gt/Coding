class Solution {
public:
    int func(string s) {
        int l=0,r=s.size()-1;
        int ans=0;
        // cout<<"s="<<s<<"\n";
        while(l<=r) {
            int a=s[l]-'a'+1,b=s[r]-'a'+1;
            int mx=max(a,b),mn=min(a,b);
            ans+=min(abs(a-b),26-mx+mn);

            // cout<<min(abs(s[l]-s[r]),abs('z'-s[l]+s[r]))<<" ";
            // cout<<abs(s[l]-s[r])<<" ";
            // cout<<26-mx+mn<<" ";

            l++;r--;
        }
        // cout<<"\n \n";
        return ans;
    }
    int minOperations(string s) {
        int n=s.size();
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++) {
            string s1=s.substr(0,i);
            reverse(s1.begin(),s1.end());
            string s2=s.substr(i,n);
            reverse(s2.begin(),s2.end());
            string s3=s1+s2;
            reverse(s3.begin(),s3.end());
            // cout<<s3<<" \n";
            ans=min(ans,func(s3)+i);
        }
        return ans;
    }
};