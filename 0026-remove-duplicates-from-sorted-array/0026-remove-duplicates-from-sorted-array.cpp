class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),i=0,j=1;
        if(n==1) return 1;
        while(i<=j && j<n) {
            int l=0;
            while(j<n && nums[i]==nums[j]) j++;
            if(j<n)
            nums[i+1]=nums[j];
            i++;
        }
        return i;
    }
};