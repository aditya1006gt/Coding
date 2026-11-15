class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);

        vector<int> order;
        order.push_back(0);

        for (int i=0;i<order.size();i++) {
            int u=order[i];

            for (int v:adj[u]) {
                order.push_back(v);
            }
        }

        vector<long long> subscore(n,0);

        reverse(order.begin(), order.end());

        for (int u:order) {

            if (adj[u].empty()) {
                subscore[u]=score[u];
                continue;
            }

            long long sc=0;
            long long mnval=LLONG_MAX;

            for(int v:adj[u]) {
                sc+=subscore[v];
                mnval=min(mnval,subscore[v]);
            }

            if(op[u]==0) {
                subscore[u]=score[u]+sc-min(0LL,mnval);
            }
            else {
                subscore[u]=score[u]+sc-mnval;
            }
        }

        return subscore[0];
    }
};