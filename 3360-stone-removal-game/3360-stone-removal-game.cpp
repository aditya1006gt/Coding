class Solution {
public:
    bool canAliceWin(int n) {
        int c=0;
        int val=10;
        while(n>=val) {
            n-=val;
            c=(c+1)%2;
            val--;
        }
        if(c==0) return false;
        return true;
    }
};