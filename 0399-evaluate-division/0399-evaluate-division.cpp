class Solution {
public:
    double func(unordered_map<string,vector<pair<string,double>>>& adj, string A, string B, unordered_set<string>& visited) {
        if(A==B) return 1.0;

        visited.insert(A);

        for(auto& i:adj[A]) {
            string t=i.first;
            double v=i.second;

            if(visited.find(t) == visited.end()) {
                double l=func(adj,t,B,visited);
                
                if(l!=-1.0) {
                    return l*v;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        int n=equations.size();
        for(int i=0;i<n;i++) {
            string A=equations[i][0];
            string B=equations[i][1];
            double num=values[i];
            adj[A].push_back({B,num});
            adj[B].push_back({A,1.0/num});
        }
        vector<double> ans;

        for(int i=0;i<queries.size();i++) {
            string A=queries[i][0];
            string B=queries[i][1];
            if(adj.find(A)==adj.end() || adj.find(B)==adj.end()) {
                ans.push_back(-1.0);
            }
            else {
                unordered_set<string> visited;
                ans.push_back(func(adj, A, B, visited));
            }
        }
        return ans;
    }
};