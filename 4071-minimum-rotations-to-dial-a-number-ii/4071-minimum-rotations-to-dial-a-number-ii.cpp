class Solution {
public:
    void minRot(const string& s, vector<int>& arr) {
        int n=s.size();
        int val=s[0]-'0',pvs=s[0]-'0';
        arr.push_back(min(val,10-val));
        for(int i=1;i<n;i++) {
            val=abs((s[i]-'0')-pvs);
            pvs=s[i]-'0';
            arr.push_back(min(val,10-val));
        }
    }
    int minRotations(int n, string s) {
        vector<int>arr;
        minRot(s,arr);
        vector<int>ssum(n);
        vector<int>psum(n);
        for(int i=0;i<n;i++) {
            int sm=(i==0)?0:psum[i-1];
            psum[i]=sm+arr[i];
        }
        for(int i=n-1;i>=0;i--) {
            int sm=(i==n-1)?0:ssum[i+1];
            ssum[i]=sm+arr[i];
        }
        int ans=psum[n-1];

        for(int i=0;i<n;i++) {
            int val=0;
            if(i!=0) val+=psum[i-1];
            if(i!=n-1) val+=ssum[i+1];
            if(i==0) {
                int d=s[n-1]-'0';
                val+=min(d,10-d);
            }
            else {
                int d=abs(s[n-1]-s[i-1]);
                val+=min(d,10-d);
            }
            ans=min(ans,val);
        }
        return ans;
    }
};