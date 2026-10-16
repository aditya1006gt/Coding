class Solution {
public:
    int calc(vector<int>& onums, vector<int>& enums, int oavg, int eavg, int k) {
        int so=0;
        for(auto& i:onums) {
            int d=abs(i-oavg);
            so+=min(d,k-d);
        }
        int se=0;
        for(auto& i:enums) {
            int d=abs(i-eavg);
            se+=min(d,k-d);
        }
        return se+so;
    }
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size(),e=n/2,o=n-e;
        vector<int>onums;
        vector<int>enums;
        for(int i=0;i<n;i++) {
            if(i%2==0) onums.push_back(nums[i]%k);
            else enums.push_back(nums[i]%k);
        }
        int ans=INT_MAX;
        for(int i=0;i<k;i++) {
            for(int j=i+1;j<k;j++) {
                ans=min({ans,calc(onums,enums,i,j,k),calc(onums,enums,j,i,k)});
            }
        }
        return ans;
    }
};