class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n)
        return findMedianSortedArrays(nums2,nums1);
        int l=0,h=m,lft=(n+m+1)/2;
        while(l<=h)
        {
            int mid1=(l+h)/2;
            int mid2=lft-mid1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<m) r1=nums1[mid1];
            if(mid2<n) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            
            if(l1<=r2 && l2<=r1)
            {
                if((m+n)%2==0)
                return ((double)(max(l1,l2))+(double)min(r1,r2))/2.0;
                return max(l1,l2);
            }
            if(l1>r2)
            h=mid1-1;
            else
            l=mid1+1;
        }
        return 0;
    }
};




















/*

int m=nums1.size(),n=nums2.size();
        if(m>n)
        return findMedianSortedArrays(nums2,nums1);
        
        int l=0,h=m,lft=(n+m+1)/2;
        while(l<=h)
        {
            int mid1=(l+h)/2;
            int mid2=lft-mid1;

            int l1=INT_MIN,l2=l1;
            int r1=INT_MAX,r2=r1;
            if(mid1<m) r1=nums1[mid1];
            if(mid2<n) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];

            if (l1 <= r2 && l2 <= r1) 
            {
            if ((n+m) % 2 == 1) 
            return max(l1, l2);
            else 
            return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }
            else if (l1 > r2) h = mid1 - 1;
            else l = mid1 + 1;
        }
        return 0;

*/








/*

int m=nums1.size(),n=nums2.size();
        vector<int> nu;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                nu.push_back(nums1[i]);
                i++;
            }
            else
            {
                nu.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)
        {
            nu.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            nu.push_back(nums2[j]);
            j++;
        }
        if((m+n)%2!=0)
        return (double)nu[(m+n)/2];
        return ((double)(nu[(m+n)/2]+(double)nu[((m+n)/2)-1])/(double)2);

*/