class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        for(int i=0;i<n;i++) {
            vector<int>freq(26,0);
            freq[0]=nums[i];
            for(int j=0;j<25;j++) {
                freq[j+1]=freq[j]/2;
                freq[j]%=2;
            }
            string stg="";
            for(int j=25;j>=0;j--) {
                if(freq[j]!=0) stg.append(freq[j],('a'+j));
            }
            ans.push_back(stg);
        }
        return ans;
    }
};