class Solution {
public:
    #define ll long long
    long long splitArray(vector<int>& nums) {
        bool ans=true;
        ll n=nums.size();
        ll maxi=0,i1=-1;
        int cnt=0;
        for(ll i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                i1=i;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                cnt++;
            }
        }
        for(ll i=i1;i>0;i--){
            if(nums[i]>nums[i-1]){
                continue;
            }
            else{
                return -1;
            }
        }
        if(i1+1<=n-1){
            for(ll i=i1+1;i<n-1;i++){
                if(nums[i]>nums[i+1]){
                    continue;
                }
                else{
                    return -1;
                }
            }
        }
        if(cnt==1){
            ll sum=0,sum1=0;
            ll y1=0,y2=0;
            for(ll i=0;i<=i1;i++){
                sum+=nums[i];
            }
            for(ll i=i1+1;i<n;i++){
                sum1+=nums[i];
            }
            for(ll i=0;i<i1;i++){
                y1+=nums[i];
            }
            for(ll i=i1;i<n;i++){
                y2+=nums[i];
            }
            return min(abs(sum-sum1),abs(y1-y2));
        }
        else{
            ll sum=0,sum1=0;
            ll y1=0,y2=0;
            for(ll i=0;i<=i1;i++){
                sum+=nums[i];
            }
            for(ll i=i1+1;i<n;i++){
                sum1+=nums[i];
            }
            return abs(sum-sum1);
        }
        return -1;
    }
};