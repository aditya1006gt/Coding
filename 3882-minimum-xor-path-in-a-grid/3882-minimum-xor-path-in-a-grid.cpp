class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(1024, false)));
        queue< pair< int, pair<int,int>> > qu;
        int ans=INT_MAX;
        qu.push({grid[0][0],{0,0}}); visited[0][0][0]=true;
        while(!qu.empty()) {
            auto valu=qu.front(); qu.pop();
            int tp=valu.first;
            int i=valu.second.first;
            int j=valu.second.second;

            if(i==n-1 && j==m-1) ans=min(tp,ans);

            int vali=i,valj=j;
            if(i!=n-1) {
                int next_xor=tp^grid[i+1][j];
                if(!visited[i+1][j][next_xor]) {
                    visited[i+1][j][next_xor]=true;
                    qu.push({next_xor,{i+1,j}});
                }
            }
            if(j!=m-1) {
                int next_xor=tp^grid[i][j+1];
                if(!visited[i][j+1][next_xor]) {
                    visited[i][j+1][next_xor]=true;
                    qu.push({next_xor,{i,j+1}});
                }
            }
        }
        return ans;
    }
};