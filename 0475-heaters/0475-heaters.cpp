class Solution {
public:
    int check(int house, vector<int>& heaters, int rad) {
        int l=0,r=heaters.size()-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if(abs(heaters[mid]-house)<=rad) return 1;
            if(heaters[mid]>house) r=mid-1;
            else l=mid+1;
        }
        return 0;
    }
    bool fun(vector<int>& houses, vector<int>& heaters, int mid) {
        for(auto& i:houses) {
            if(!check(i,heaters,mid)) return 0;
        }
        return 1;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int ans=-1;
        int l=0,r=1e9+1;
        while(l<=r) {
            int mid=l-(l-r)/2;

            if(fun(houses,heaters,mid))
            r=mid-1;
            else
            l=mid+1;
        }
        return l;
    }
};