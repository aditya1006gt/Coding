class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(begin(occupiedIntervals),end(occupiedIntervals));
        vector<vector<int>> arr;

        arr.push_back({occupiedIntervals[0][0],occupiedIntervals[0][1]});
        int k=occupiedIntervals.size();
        for(int i=1;i<k;i++) {
            int l=occupiedIntervals[i][0];
            int r=occupiedIntervals[i][1];
            if(arr.back()[1]+1<l) {
                arr.push_back({occupiedIntervals[i][0],occupiedIntervals[i][1]});
            }
            else {
                arr.back()[1]=max(r,arr.back()[1]);
            }
        }

        vector<vector<int>> ans;
        for(auto& i:arr) {
            int l=i[0],r=i[1];
            if(r<freeStart || l>freeEnd) {
                ans.push_back({l,r});
            }
            else if(r>=freeStart && l<freeStart && r<=freeEnd) {
                ans.push_back({l,freeStart-1});
            }
            else if(l<=freeEnd && r>freeEnd && l>=freeStart) {
                ans.push_back({freeEnd+1,r});
            }
            else if(r>freeEnd && l<freeStart) {
                ans.push_back({l,freeStart-1});
                ans.push_back({freeEnd+1,r});
            }
        }
        return ans;
    }
};