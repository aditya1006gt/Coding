class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        vector<int> spd;
        for (int i=0;i<n;i++) {
            if (i==n-1 || position[i+1]-position[i]>distance) spd.push_back(speed[i]);
        }
        
        vector<int>st;
        for (int v:spd) {
            while (!st.empty() && st.back()>v) st.pop_back();

            st.push_back(v);
        }
        
        return st.size();
    }
};