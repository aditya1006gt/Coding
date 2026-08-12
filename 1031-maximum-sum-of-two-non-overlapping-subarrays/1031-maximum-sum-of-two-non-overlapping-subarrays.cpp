class Solution {
public:
    int sum(vector<int>& nums, vector<int>& psum, int firstLen, int secondLen) {
        int n=nums.size();
        int a=INT_MIN;
        for(int i=firstLen-1;i<n;i++) {
            int s1=psum[i];
            if(i-firstLen>=0) s1-=psum[i-firstLen];
            if(i+secondLen>n) break;
            for(int j=i+1;j+secondLen<=n;j++) {
                int s2=psum[j+secondLen-1];
                s2-=psum[j-1];
                a=max(a,s1+s2);
            }
        }
        cout<<"a="<<a<<" \n";
        return a;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int>psum(n,0); 
        psum[0]=nums[0];
        for(int i=1;i<n;i++) psum[i]+=psum[i-1]+nums[i];

        int x=sum(nums,psum,firstLen,secondLen);
        cout<<"x="<<x<<" \n";
        int y=sum(nums,psum,secondLen,firstLen);
        cout<<"y="<<y<<" \n";

        return max(x,y);
    }
};