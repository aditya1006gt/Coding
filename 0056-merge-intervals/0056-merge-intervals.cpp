class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(auto i:intervals) {
            if(!ans.empty() && ans[ans.size()-1][1]>=i[0]) ans[ans.size()-1][1]=max(i[1],ans[ans.size()-1][1]);
            else
            ans.push_back({i[0],i[1]});
        }
        return ans;
    }
};