class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        set<int>st;
        set<int>pvs;
        for(int i=0;i<n;i++)
        {
            set<int>curr;
            curr.insert(arr[i]);
            st.insert(arr[i]);
            for(auto j:pvs)
            {
                curr.insert(j|arr[i]);
                st.insert(j|arr[i]);
            }
            pvs=curr;
        }
        return st.size();
    }
};