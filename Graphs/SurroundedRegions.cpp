#include<bits/stdc++.h>
using namespace std;

bool isOk(int i,int j,int n,int m,vector<vector<bool>>&vis)
{
    if(i<0||j<0||i>=n||j>=m||vis[i][j]==true) return false;
    
    return true;
}

void dfs(vector<vector<char>>&board,int n,int m,int i,int j,vector<vector<bool>>&vis)
{
       vis[i][j]=true;
       if(isOk(i+1,j,n,m,vis)&&board[i+1][j]=='O')
        dfs(board,n,m,i+1,j,vis);
        
        if(isOk(i,j+1,n,m,vis)&&board[i][j+1]=='O')
        dfs(board,n,m,i,j+1,vis);

        if(isOk(i-1,j,n,m,vis)&&board[i-1][j]=='O')
        dfs(board,n,m,i-1,j,vis);

        if(isOk(i,j-1,n,m,vis)&&board[i][j-1]=='O')
        dfs(board,n,m,i,j-1,vis);

}

int main()
{
    vector<vector<char>>board={
        {'X','X','X','X'},
        {'O','O','O','X'},
        {'X','X','O','X'},
        {'X','X','X','X'}
    };

    int n=board.size();
    int m=board[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for (int i = 0; i < m; i++){
        if(board[0][i]=='O'&&!vis[0][i])dfs(board,n,m,0,i,vis);
        if(board[n-1][i]=='O'&&!vis[n-1][i])dfs(board,n,m,n-1,i,vis);
        }

    for (int i = 0; i < n; i++){
        if(board[i][0]=='O')dfs(board,n,m,i,0,vis);
        if(board[i][m-1]=='O')dfs(board,n,m,i,m-1,vis);
    }
    
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j])cout<<'x';
            else cout<<'o';
        }
        cout<<endl;
        
    }
    

    return 0;
}