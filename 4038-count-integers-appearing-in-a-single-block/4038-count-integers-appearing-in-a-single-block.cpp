class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        map<int,int>mpp;
        map<int,int>mpp2;
        for(int i=0;i<n;i++) {
            int num=nums[i];

            if(mpp.find(num)==end(mpp)) {
                mpp[num]=i;
                ans++;
            }
            else if(mpp[num]+1==i) {
                mpp[num]=i;
            }
            else {
                if(mpp2.find(num)==end(mpp2)) ans--;

                mpp2[num]=1;
            }
        }
        return ans;
    }
};