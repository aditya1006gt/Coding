class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++) {
            string stg=s.substr(i,n-i)+s.substr(0,i);

            int score=0;
            int j=1;
            while(j<n) {
                if(stg[j]==stg[j-1]) score++;
                j++;
            }
            if(score==k) ans++;
        }
        return ans;
    }
};