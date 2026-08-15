class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans=0,lst=0;
        for(auto& i:requests) {
            ans+=abs(i-lst);
            lst=i;
        }
        return ans;
    }
};