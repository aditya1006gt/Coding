class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        int k=INT_MAX;
        for(int i=0;i<n;i++) {
            if(nums[i]!=arr[i]) {
                k&=nums[i];
            }
        }
        return (k==INT_MAX)?0:k;
    }
};