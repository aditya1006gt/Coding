class Solution {
public:
    void palin(vector<long long>& evens, vector<long long>& odds, bool& precomputed) {
        for (int i=1;i<=100000;i++) {
            string s=to_string(i);
            string r=s;
            reverse(r.begin(),r.end());
            
            long long p1=stoll(s+r);
            if (p1%2==0) evens.push_back(p1);
            else odds.push_back(p1);
            
            long long p2=stoll(s+r.substr(1));
            if (p2%2==0) evens.push_back(p2);
            else odds.push_back(p2);
        }

        sort(evens.begin(),evens.end());
        sort(odds.begin(),odds.end());
        precomputed=true;
    }
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        
        static vector<long long>evens,odds;
        static bool precomputed = false;
        if (!precomputed) palin(evens,odds,precomputed);
        
        for(auto& i:nums) {
            const vector<long long>& pal=(i%2==0)?evens:odds;
            int ind=lower_bound(pal.begin(),pal.end(),i)-pal.begin();

            long long mn=2e18;
            if(ind<pal.size()) {
                mn=min(mn,abs(pal[ind]-i));
            }
            if(ind>=1) {
                mn=min(mn,abs(pal[ind-1]-i));
            }
            ans+=(mn/2);
        }
        return ans;
    }
};