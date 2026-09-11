class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int l=cbrt(n)+1;
        map<int,set<int>>mpp;
        for(int i=1;i<=l;i++) {
            int val1=i*i*i;
            for(int j=1;j<i;j++) {
                int val2=j*j*j;
                if(val1+val2<=n) {
                    mpp[val1+val2].insert({i,j});
                }
            }
        }

        vector<int>ans;
        for(auto& i:mpp) {
            // cout<<"fst="<<i.first<<" ";
            // for(auto& j:i.second) cout<<j<<" ";
            // cout<<"\n";
            if(mpp[i.first].size()>=4) ans.push_back(i.first);
        }
        return ans;
    }
};