class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++) {
            int indr=i+arr[i];
            int indl=i-arr[i];
            if(indr<n)
            adj[i].push_back(indr);
            if(indl>=0)
            adj[i].push_back(indl);
        }
        vector<int>vis(n);
        queue<int>q;
        q.push(start);
        while(!q.empty()) {
            auto node=q.front();
            q.pop();
            if(vis[node]) continue;
            vis[node]=1;

            for(auto& i:adj[node]) {
                if(i==node) return true;
                if(vis[i]==1) continue;

                q.push(i);
            }
        }
        return 0;
    }
};