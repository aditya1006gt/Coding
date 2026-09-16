class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++) {
            if(words[i][0]=='a') continue;

            int r=words[i][0]-'a';r=26-r;
            int l=words[i].size();
            for(int j=0;j<l;j++) {
                int v=words[i][j]-'a';
                words[i][j]=((v+r)%26)+'a';
            }
        }
        // for(auto& i:words) cout<<"i="<<i<<" ";

        unordered_map<string,int>mpp;
        long long ans=0;
        for(auto& i:words) {
            ans+=mpp[i];
            mpp[i]++;
        }
        return ans;
    }
};