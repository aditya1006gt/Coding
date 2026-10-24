class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while (mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
















/*
brute force 
void sortColors(vector<int>& nums) {
        qs(nums, 0, nums.size()-1);
    }
    void qs(vector<int>& nums, int l, int h)
    {
        if(l>=h)
        return;
        int p=ptn(nums, l, h);
        qs(nums, l, p-1);
        qs(nums,p+1,h);
    }
    int ptn(vector<int>& nums, int l, int h)
    {
        int pvt=nums[l],i=l,j=h;
        while(i<j)
        {
            while(nums[i]<=pvt && i<=h-1)
            i++;
            while(nums[j]>pvt && j>=l+1)
            j--;
            if(i<j)
            swap(nums[i],nums[j]);
        }
        swap(nums[l],nums[j]);
        return j;
    }
*/