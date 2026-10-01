#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>pbds;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        pbds st;
        pbds st2;
        vector<int> a;
        vector<int> b;
        vector<int> ans;
        st.insert({nums[0],0});
        a.push_back(nums[0]);
        st2.insert({nums[1],1});
        b.push_back(nums[1]);
        for(int i=2;i<n;i++)
        {
            int n1=a.size(),n2=b.size();
            int ind=st.order_of_key({nums[i], INT_MAX});
            int ind2=st2.order_of_key({nums[i], INT_MAX});
            if(n1-ind>n2-ind2)
            {
                st.insert({nums[i],i});
                a.push_back(nums[i]);
            }
            else if(n1-ind<n2-ind2)
            {
                st2.insert({nums[i],i});
                b.push_back(nums[i]);
            }
            else
            {
                if(st.size()<=st2.size())
                {
                    st.insert({nums[i],i});
                    a.push_back(nums[i]);
                }
                else
                {
                    st2.insert({nums[i],i});
                    b.push_back(nums[i]);
                }
            }
        }
        for(auto i:a) ans.push_back(i);
        for(auto i:b) ans.push_back(i);
        return ans;
    }
};