class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num<sum) return "";

        string ans="";
        while(num>0) {
            if(sum>=9) {
                ans+="9";
                sum-=9;
            }
            else {
                ans+=to_string(sum);
                sum=0;
            }
            num--;
        }
        return ans;
    }
};