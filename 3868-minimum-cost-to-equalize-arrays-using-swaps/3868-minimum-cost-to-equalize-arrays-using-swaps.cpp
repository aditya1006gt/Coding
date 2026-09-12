class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        for(auto& i:nums1) {
            mpp1[i]++;
            mpp[i]++;
        }
        for(auto& i:nums2) {
            mpp2[i]++;
            mpp[i]++;
        }

        int ans=0;
        for(auto& i:mpp) {
            if(i.second%2==1) return -1;
            ans+=(abs(mpp1[i.first]-mpp2[i.first])/2);
        }
        return ans/2;
    }
};