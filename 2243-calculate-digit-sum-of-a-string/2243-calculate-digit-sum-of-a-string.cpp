class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        if(n<=k) return s;

        while(n>k) {
            string stg=s;
            string ttlval="";
            for(int i=0;i<n;i+=k) {
                int val=0;
                for(int j=0;j<k && j+i<n;j++) {
                    val+=(s[j+i]-'0');
                }
                // cout<<"val="<<val<<"\n";
                ttlval+=to_string(val);
            }
            s=ttlval;
            // cout<<"ttlval="<<ttlval<<"\n";
            n=s.size();
        }
        return s;
    }
};