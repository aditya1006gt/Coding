class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        sort(words.begin(),words.end());
        vector<vector<string>> ans;
        int n=words.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j || words[i][0]!=words[j][0]) continue;

                for(int k=0;k<n;k++) {
                    if(i==k || j==k || words[i][3]!=words[k][0]) continue;

                    for(int l=0;l<n;l++) {
                        if(i==l || j==l ||k==l || words[j][3]!=words[l][0] || words[k][3]!=words[l][3]) continue;

                        ans.push_back({words[i],words[j],words[k],words[l]});
                    }
                }
            }
        }
        return ans;
    }
};