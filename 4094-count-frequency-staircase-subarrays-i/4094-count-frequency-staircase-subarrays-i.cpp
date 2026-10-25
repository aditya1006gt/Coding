class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for (int i=0;i<n;i++) {
            unordered_map<int,int>freq;
            vector<int>order;

            for(int j=i;j<n;j++) {
                int val=nums[j];
                if (freq[val]==0) {
                    order.push_back(val);
                }
                freq[val]++;

                int k=order.size();
                int len=j-i+1;
                long long expectedLen=1LL*k*(k+1)/2;

                if(len==expectedLen) {
                    bool valid=true;
                    for (int m=0;m<k;m++) {
                        if(freq[order[m]]!=m+1) {
                            valid=0;
                            break;
                        }
                    }
                    if(valid) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};