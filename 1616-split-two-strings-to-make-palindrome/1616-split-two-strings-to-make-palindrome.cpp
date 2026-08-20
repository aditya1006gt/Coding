class Solution {
public:
    bool palin(const string& s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<=r) {
            if(s[l]!=s[r]) return 0;
            l++;r--;
        }
        return 1;
    }
    bool check(const string& a, const string& b) {
        int n=a.size();
        int l=0,r=n-1,c=0;
        while(a[l]==b[r]) {
            l++;r--;
            c++;
            if(2*c>=n) return 1;
        }
        int l1=l,r1=n-1-c;
        int f1=0,f2=0;
        while(l1<=r1) {
            if(a[l1]!=a[r1]) {
                f1=1;
                break;
            }
            l1++;r1--;
        }

        while(l<=r) {
            if(b[l]!=b[r]) {
                f2=1;
                break;
            }
            l++;r--;
        }

        if(f1==1 && f2==1) return 0;
        return 1;
    }
    bool checkPalindromeFormation(string a, string b) {
        int n=a.size();
        if(palin(a) || palin(b)) {
            return true;
        }
        if(check(a,b) || check(b,a)) return true;
        return false;
    }
};