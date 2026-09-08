class Solution {
public:
    bool isPalindrome(int x) {
        long long r=0;
        for(long long i=x;i>0;i/=10)
        r=r*10+i%10;
        return r==x;
    }
};