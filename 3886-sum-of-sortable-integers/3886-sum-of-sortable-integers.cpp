class Solution {
public:
    bool cycfunc(vector<int>& nums, int k) {
        int n = nums.size();
        for (int b=0;b<n;b+=k) {
            int drops=0;
            for (int i=0;i<k;i++) {
                int curr=nums[b+i];
                int next=nums[b+((i+1)%k)];
                if(curr>next) {
                    drops++;
                }
            }
            if(drops>1) return false;
        }
        return true;
    }
    // bool cycfunc(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     int cnt=0,drp=0;
    //     for (int i=0;i<n;i++) {
    //         if (nums[i]>nums[((i+1)%k)+((i/k)*k)]) {cnt++;drp++;}

    //         if(i%k==0 && drp>1) return 0;
    //         if(i%k==0) drp=0;
    //     }
    //     return cnt>=k;
    // }
    bool chkfunc(vector<int>& nums, int k) {
        int n=nums.size();
        int pmn=INT_MAX,pmx=INT_MIN;
        for(int i=0;i<k;i++) {
            pmn=min(nums[i],pmn);
            pmx=max(nums[i],pmx);
        }
        int cmn=INT_MAX;
        int cmx=INT_MIN;
        for(int i=k;i<n;i++) {
            cmn=min(nums[i],cmn);
            cmx=max(nums[i],cmx);
            if(i%k==k-1) {

                if(pmn>cmn || pmx>cmx || pmx>cmn) return 0;
                
                pmn=cmn;
                pmx=cmx;

                cmn=INT_MAX;
                cmx=INT_MIN;
                continue;
            }
        }
        return 1;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>div;
        int ans=0;
        for(int i=1;i*i<=n;i++) {
            if(n%i==0) {
                div.push_back(i);
                ans+=i;
                if(n/i!=i) {
                    div.push_back(n/i);
                    ans+=(n/i);
                }
            }
        }

        for(auto& i:div) {
            if(!chkfunc(nums,i) || !cycfunc(nums,i)) ans-=i;
        }
        return ans;
    }
};