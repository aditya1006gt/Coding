class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string stg1="",stg2="";
        for(int i=0;i<n-1;i++) {
            stg1+=".";
            stg2+="#";
        }
        vector<string> ans;
        for(int i=0;i<m;i++) {
            string s=stg2;
            if(i==0) s=stg1;
            ans.push_back(s+".");
        }
        return ans;
    }
};