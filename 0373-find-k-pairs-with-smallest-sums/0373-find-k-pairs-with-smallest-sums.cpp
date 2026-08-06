class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        int l=0,r=0;
        int m=nums1.size(),n=nums2.size();
        priority_queue< 
        pair<int, pair<int,int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;

        for(int i=0;i<m;i++) {
            pq.push({nums1[i]+nums2[0],{i, 0}});
        }

        while(k>0 && !pq.empty()) {
            auto current=pq.top();
            pq.pop();
            
            int i=current.second.first;
            int j=current.second.second;
            
            ans.push_back({nums1[i], nums2[j]});
            
            if(j+1<n) {
                pq.push({nums1[i]+nums2[j+1], {i,j+1}});
            }
            k--;
        }
        return ans;
    }
};