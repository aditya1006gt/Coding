class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int sum=INT_MAX;
        for(int i=0;i<n;i++) {
            int s=0;
            for(int j=i;j<n;j++) {
                s+=nums[j];
                int len=j-i+1;
                if(len<l) continue;
                if(len>r) break;
                if(s<=sum&&s>0) {
                    sum=s;
                }
            }
        }
        return sum!=INT_MAX?sum:-1;
    }
};