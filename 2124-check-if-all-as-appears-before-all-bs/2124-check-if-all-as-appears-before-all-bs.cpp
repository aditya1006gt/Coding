class Solution {
public:
    bool checkString(string s) {
        int b=-1;
        for(auto& i:s) {
            if(i=='a') {
                if(b!=-1) return false;
            }
            else {
                b=1;
            }
        }
        return true;
    }
};