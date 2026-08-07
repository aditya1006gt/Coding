class Solution {
public:
    int calc(vector<vector<int>>& matrix, int mid) {
        int n=matrix.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            if(matrix[i][0]>mid) break;

            int r=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            ans+=r;
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<=r) {
            int mid=(l+r)/2;
            int count=calc(matrix,mid);
            if(count<k) {
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        return l;
    }
};