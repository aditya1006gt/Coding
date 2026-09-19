class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0) return -1;
        int r=1%k;
        int val=1;
        while(r!=0) {
            r=((r*10)+1)%k;
            val++;
        }
        return r==0?val:-1;
    }
};