class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(auto& i:chunks) s+=i;

        int n=s.size();
        string stg="";
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++) {
            if('a'<=s[i] && s[i]<='z') stg+=s[i];

            else if(s[i]==' ') {
                mpp[stg]++;
                cout<<stg<<" \n";
                stg="";
            }
            else if(i!=0 && i!=n-1 && s[i]=='-' && ('a'<=s[i-1] && s[i-1]<='z') && ('a'<=s[i+1] && s[i+1]<='z')) stg+=s[i];

            else {
                cout<<stg<<" \n";
                mpp[stg]++;
                stg="";
            }
        }
        if(stg!="") mpp[stg]++;

        vector<int> ans;
        for(auto& i:queries) {
            ans.push_back(mpp[i]);
        }
        return ans;
    }
};