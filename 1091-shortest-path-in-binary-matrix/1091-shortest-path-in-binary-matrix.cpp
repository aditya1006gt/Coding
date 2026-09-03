class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) 
        return -1;
        vector<vector<int>>path(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(path[i][j]==1) path[i][j]=grid[i][j];
            }
        }

        set<pair<int, pair<int,int>>>st;
        st.insert({1,{0,0}});
        path[0][0]=1;
        while(!st.empty()) {
            auto it=*st.begin();
            int d=it.first;
            int i=it.second.first;
            int j=it.second.second;
            st.erase(st.begin());

            int row[]={0,0,1,-1,1,1,-1,-1};
            int col[]={1,-1,0,0,1,-1,1,-1};
            for(int k=0;k<8;k++) {
                int r=i+row[k];
                int c=j+col[k];
                if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==0 && d+1<path[r][c]) {
                    path[r][c]=d+1;
                    st.insert({d+1,{r,c}});
                } 
            }
        }
        return (path[n-1][n-1]==INT_MAX)?-1:path[n-1][n-1];
    }
};