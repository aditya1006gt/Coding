class Solution {
public:
    string maximumXor(string s, string t) {
        int n=s.size();
        string ans=s;
        int zs=0,ot=0;
        for(auto& i:s) {
            if(i=='0') zs++;
        }
        for(auto& i:t) {
            if(i=='1') ot++;
        }

        if(ot==0) return s;

        if(ot>zs) {
            int c=0;
            int l=ot-zs;
            for(int i=n-1;i>=0;i--) {
                if(s[i]=='1') {
                    ans[i]='0';
                    c++;
                }
                if(c==l) break;
            }
            c=0;
            for(int i=0;i<n;i++) {
                if(s[i]=='0') {
                    ans[i]='1';
                    c++;
                }
                if(c==zs) return ans;
            }
        }
        int c=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') {
                ans[i]='1';
                c++;
            }
            if(c==ot) break;
        }
        return ans;
    }
};