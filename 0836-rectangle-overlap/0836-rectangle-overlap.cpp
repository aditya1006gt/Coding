class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool xo=false;
        if(rec1[0]<rec2[2] && rec2[0]<rec1[2]) xo=1;
        
        bool yo=false;
        if(rec1[1]<rec2[3] && rec2[1]<rec1[3]) yo=1;
         
        return xo && yo;
    }
};