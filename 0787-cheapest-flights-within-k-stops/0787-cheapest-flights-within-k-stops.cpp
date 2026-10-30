class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++) {
            int a=flights[i][0];
            int b=flights[i][1];
            int c=flights[i][2];
            adj[a].push_back({b,c});
        }
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{src,k}});
        vector<int>netcost(n,INT_MAX);
        netcost[src]=0;k++;
        while(!pq.empty()) {
            int cost=pq.front().first;
            int curr=pq.front().second.first;
            int kval=pq.front().second.second;
            pq.pop();
            if(kval<0) break;

            for(auto& [nxt,ct]:adj[curr]) {
                if(ct+cost<netcost[nxt]) {
                    netcost[nxt]=ct+cost;
                    pq.push({ct+cost,{nxt,kval-1}});
                }
            }
        }
        return netcost[dst]==INT_MAX?-1:netcost[dst];
    }
};