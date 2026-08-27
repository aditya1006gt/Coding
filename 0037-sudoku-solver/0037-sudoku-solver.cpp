class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fun(board);
        
    }
    bool fun(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(chk(board,k,i,j))
                        {
                            board[i][j]=k;

                            if(fun(board))
                            return true;

                            else
                            board[i][j]='.';
                        }
                    }
                    return false; 
                }
            }
        }
        return true;
    }
    bool chk(vector<vector<char>>& board,char a,int row,int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==a || board[i][col]==a)
            return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == a)
            return false;
        }
        return true;
    }
};


/* why this is not working
void solveSudoku(vector<vector<char>>& board) 
    {
        vector<vector<int>>rw(9,vector<int>(9,0));
        vector<vector<int>>cm(9,vector<int>(9,0));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    rw[char(board[i][j])-'1'][i]=1;
                    cm[char(board[i][j])-'1'][i]=1;
                }
            }
        }
        fun(0,board,rw,cm);
    }

    bool fun( int row,vector<vector<char>>& board,vector<vector<int>>& rw,vector<vector<int>>& cm)
    {
        if(row==9)
        return true;

        else if(row<9)
        {
        for(int col=1;col<=9;col++)
        {
            if(board[row][col-1]!='.')
            continue;
            
            int i;
            for(i=0;i<9;i++)
            {
                if(ck(rw,i+1) || ck(cm,i+1) || chk(row,col,i+1,board))
                continue;
            }
            if(i<9){
            rw[i][row]=1;
            cm[i][col-1]=1;
            board[row][col-1]='0'+(i+1);
            if(fun(col+1,board,rw,cm))
            return true;

            rw[i][row]=0;
            cm[i][col-1]=0;
            board[row][col-1]='.';
            }
        }
        }

        return false;
    }

    bool chk(int row,int col,int a,vector<vector<char>>& board)
    {
        int x1,x2,y1,y2;
        if(row<=2) {x1=0;x2=2;}
        else if(row<=5) {x1=3;x2=5;}
        else {x1=6;x2=8;}

        if(col<=2) {y1=0;y2=2;}
        else if(col<=5) {y1=3;y2=5;}
        else {y1=6;y2=8;}

        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                if(board[i][j]!='.' && board[i][j]-'0'==a)
                return true;
            }
        }
        return false;
    }

    bool ck(vector<vector<int>>& f,int t)
    {
        for(int i=0;i<9;i++)
        {
            if(f[t-1][i]==1)
            return true;
        }
        return false;
    }
    */