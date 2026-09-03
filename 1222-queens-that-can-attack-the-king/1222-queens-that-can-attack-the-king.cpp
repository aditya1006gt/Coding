class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n=queens.size();
        vector<vector<bool>> arr(8, vector<bool>(8,0));
        for (auto& q:queens) {
            arr[q[0]][q[1]]=true;
        }

        int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0}, {1,1},{1,-1},{-1,1},{-1,-1}
        };
        
        vector<vector<int>> ans;
        for (auto& d:dir) {
            int r=king[0];
            int c=king[1];

            while(true) {
                r+=d[0];
                c+=d[1];
                
                if(r<0 || r>=8 || c<0 || c>=8) break;
                
                if(arr[r][c]) {
                    ans.push_back({r, c});
                    break; 
                }
            }
        }
        return ans;
    }
};