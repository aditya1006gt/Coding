class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mi=max(mi,i+nums[i]);
            if(nums[i]==0 && mi<=i && i!=n-1)
            return false;
        }
        return true;
    }
};


/*
        int n=nums.size();
        if(n==1)
        return 1;
        if(nums[0]==0)
        return 0;
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            a.push_back(i);
        }

        int m=a.size();
        for(int i=0;i<m;i++)
        {
            int p=0;
            for(int j=a[i]-1;j>=0;j--)
            {
                if(a[i]-j<nums[j])
                {
                    p=1;
                    break;
                }
                else if(a[i]-j<=nums[j] && i==m-1 && a[i]==n-1)
                {
                    p=1;
                    break;
                }
            }
            if(p==1)
            a[i]=-1;
        }
        for(int i=0;i<m;i++)
        {
            if(a[i]!=-1)
            return false;
        }
        return true;
*/