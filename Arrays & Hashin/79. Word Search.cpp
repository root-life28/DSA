#include <bits/stdc++.h>
using namespace std;
bool DFS(vector<vector<char>>&vr,int i,int j,string &word,int windex)
{   if(windex == word.length() - 1) return true;

        vr[i][j] -= 65;
        if(i > 0 && vr[i-1][j] == word[windex+1] && DFS(vr, i-1, j, word, windex+1)) return true;

        else if(j > 0 && vr[i][j-1] == word[windex+1] && DFS(vr, i, j-1, word, windex+1)) return true;

        else if(i < vr.size()-1 && vr[i+1][j] == word[windex+1] && DFS(vr, i+1, j, word, windex+1)) return true;

        else  if(j < vr[0].size()-1 && vr[i][j+1] == word[windex+1] && DFS(vr, i, j+1, word, windex+1)) return true;
       
        vr[i][j] += 65;
        return false;
}

bool solve(vector<vector<char>>&vr,string words)
{
    for (int i = 0; i <vr.size(); i++)
    {
        for (int j = 0; j <vr[0].size(); j++)
        
            if(vr[i][j]==words[0]&&DFS(vr,i,j,words,0))return true;
         
        
    }
    return false;
}

int main()
{
    vector<vector<char>>vr={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string words="ABCCED";
  cout<<solve(vr,words);
    return 0;
}