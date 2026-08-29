class Solution {
public:
    int func(const vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        
        vector<int>pgcd(n);
        for(int i=0;i<n;i++) {
            if(i==0) pgcd[i]=nums[i];
            else pgcd[i]=gcd(pgcd[i-1],nums[i]);
        }

        vector<int>sgcd(n);
        for(int i=n-1;i>=0;i--) {
            if(i==n-1) sgcd[i]=nums[i];
            else sgcd[i]=gcd(sgcd[i+1],nums[i]);
        }
        int val=0;
        for(int i=0;i<n-1;i++) {
            if(pgcd[i]==sgcd[i+1]) val++;
        }
        return val;
    }
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        
        int ans=func(nums);
        for(int i=0;i<n;i++) {
            vector<int> arr(nums.begin(),nums.begin()+i);
            arr.insert(arr.end(),nums.begin()+i+1,nums.end());

            ans=max(ans,func(arr));
        }
        return ans;
    }
};