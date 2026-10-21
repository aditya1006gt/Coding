class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string stg=s;
        sort(stg.begin(),stg.end());
        // string stg2=stg;
        // reverse(stg2.begin(),stg2.end());

        if(n==1 || s==stg) return 0;
        else if(n==2 && s!=stg) return -1;
        else if(stg[0]==s[0] || s[n-1]==stg[n-1]) return 1;

        string stg2=s;
        sort(stg2.begin(),stg2.end()-1);
        sort(stg2.begin()+1,stg2.end());
        if(stg2==stg) return 2;

        stg2=s;
        sort(stg2.begin()+1,stg2.end());
        sort(stg2.begin(),stg2.end()-1);
        if(stg2==stg) return 2;
        // cout<<"stg2= "<<stg2<<"\n";
        // cout<<"stg= "<<stg<<"\n";
        return 3;
    }
};