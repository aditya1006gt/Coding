class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n1=s.size(),n2=t.size();
        if(n1>n2) return 0;

        

        vector<int>arrl(n1,-1);
        int i=0,j=0;
        while(i<n1 && j<n2) {
            while(j<n2 && s[i]!=t[j]) j++;
            if(j<n2) {
                arrl[i]=j;
                j++;
            }
            else break;
            
            i++;
        }
        if(arrl[n1-1]!=-1)
        return 1;

        vector<int>arrr(n1,-1);
        i=n1-1,j=n2-1;
        while(i>=0 && j>=0) {
            while(j>=0 && s[i]!=t[j]) j--;
            if(j>=0) {
                arrr[i]=j;
                j--;
            }
            else break;
            i--;
        }
        for(int i=0;i<n1;i++) {
            bool lbool= (i==0) || arrl[i-1]!=-1;
            bool rbool= (i==n1-1) || arrr[i+1]!=-1;

            if(lbool && rbool) {
                int p=(i==0)?-1:arrl[i-1];
                int next=(i==n1-1)?n2:arrr[i+1];
                if(next-p>=2) return 1;
            }
        }
        return 0;
    }
};