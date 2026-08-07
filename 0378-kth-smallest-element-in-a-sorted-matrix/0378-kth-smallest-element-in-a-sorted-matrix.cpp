class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        vector<int>arr;
        for(auto& i:matrix) {
            for(auto&j :i) arr.push_back(j);
        }
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};