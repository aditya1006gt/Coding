class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string>mpp;
        mpp[2000]="MM";mpp[3000]="MMM";
        mpp[1000]="M";
        mpp[900]="CM";
        mpp[600]="DC";mpp[700]="DCC";mpp[800]="DCCC";
        mpp[500]="D";
        mpp[400]="CD";
        mpp[300]="CCC";mpp[200]="CC";
        mpp[100]="C";
        mpp[90]="XC";
        mpp[80]="LXXX";mpp[70]="LXX";mpp[60]="LX";
        mpp[50]="L";
        mpp[40]="XL";
        mpp[30]="XXX";
        mpp[20]="XX";
        mpp[10]="X";
        mpp[9]="IX";
        mpp[8]="VIII";
        mpp[7]="VII";
        mpp[6]="VI";
        mpp[5]="V";
        mpp[4]="IV";
        mpp[3]="III";
        mpp[2]="II";
        mpp[1]="I";

        int p=0;
        string ans="";
        for(int i=num;i>0;i=i%p)
        {
            p=pow(10,floor(log10(i)));
            int d=i/p;
            d*=p;
            ans+=mpp[d];
        }
        return ans;
    }
};