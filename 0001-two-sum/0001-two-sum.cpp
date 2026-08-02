class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=nums.size();
        map<int,int> mpp;
        for(int i=0;i<l;i++) 
        {
            int t=target -nums[i];
            
            if(mpp.find(t)!=mpp.end())
            return {mpp[t],i};

            mpp[nums[i]]=i; 
        }
        return {-1,-1};
    }
};



/*
this will tell only tell us if element is present or not

int l=nums.size();
        sort(begin(nums),end(nums));
        int i=0,j=l-1;
        while(i<=j) 
        {
            if(nums[i]+nums[j]==target)
            return true;
            else if(nums[i]+nums[j]>target)
            j--;
            else
            i++;
        }
        return false;

*/













/* brute force
int l=nums.size(),s=0;
        for(int i=0;i<l;i++) 
        {
            for(int j=i+1;j<l;j++) 
            {
                if(j!=i && (nums[i]+nums[j])==target)
                return {i,j};
            }
        }
        return {0,0};
*/