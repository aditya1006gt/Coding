class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size(),x=0,y=0;
        vector<int>hashsecret(10);
        vector<int>hashguess(10);
        for(int i=0;i<n;i++) {
            if(secret[i]==guess[i]) {
                x++;
                continue;
            }
            hashguess[guess[i]-'0']++;
            hashsecret[secret[i]-'0']++;
        }
        for(int i=0;i<10;i++)
        {
            if(hashguess[i]==0 || hashsecret[i]==0) continue;
            if(hashguess[i]!=0 &&hashsecret[i]!=0) y+=min(hashguess[i],hashsecret[i]);
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};