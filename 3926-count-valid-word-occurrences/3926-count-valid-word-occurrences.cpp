class Solution {
public:
    bool check(char c) {
        return 'a'<=c && c<='z';
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        int n=chunks.size();
        string stg="";
        for(int i=0;i<n;i++) {
            stg+=chunks[i];
        }

        n=stg.size();
        string wrd="";
        map<string,int>mpp;
        for(int i=0;i<n;i++) {
            if(i!=0 && i!=n-1 && stg[i]=='-' && check(stg[i-1]) && check(stg[i+1])) {
                wrd+='-';
            }
            else if(check(stg[i])) {
                wrd+=stg[i];
            }
            else {
                if(wrd!="")
                mpp[wrd]++;
                wrd="";
            }
        }
        if(wrd.size()!=0) mpp[wrd]++;
        // for(auto& i:mpp) cout<<"first="<<i.first<<" \n";
        vector<int>ans;
        for(auto& i:queries) {
            ans.push_back(mpp[i]);
        }

        return ans;
    }
};