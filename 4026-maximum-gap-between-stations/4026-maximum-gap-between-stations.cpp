class Solution {
public:
    // void calc(string skill, string station, string stg, int d, int p, int i, int& ans) {
    //     int n=station.size();
    //     if(i==n) {
    //         if(stg==skill) ans=max(ans,d);
    //         return;
    //     }
    //     calc(skill,station,stg,d,p,i+1,ans);
    //     d=max(d,i-p+1);
    //     calc(skill,station,stg+station[i],d,i,i+1,ans);
    // }
    int maximumGap(string skill, string station) {
        int n=skill.length();
        int m=station.length();
        if(skill.length()<=1) return 0;
        vector<int>lft(n);
        int j=0;
        for(int i=0;i<n;i++) {
            while(j<m && station[j]!=skill[i]) j++;
            lft[i]=j;
            j++;
        }

        vector<int> rht(n);
        j=m-1;
        for (int i=n-1;i>=0;i--) {
            while (j>=0 && station[j]!=skill[i]) j--;
            rht[i]=j;
            j--;
        }
        int ans=0;
        for(int i=1;i<n;i++) {
            ans=max(ans,rht[i]-lft[i - 1]);
        }
        return ans;
    }
};