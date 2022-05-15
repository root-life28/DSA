#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>&matrix)
{
     int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    
    // reverse(matrix.begin(),matrix.end());

    // for (int i = 0; i <matrix.size(); i++)
    // {
    //     for (int j =i+1; j < matrix.size(); j++)
    //     {
    //         swap(matrix[i][j],matrix[j][i]);
    //     }
        
    // }
    
 
   
}

int main()
{
    //vector<vector<int>>vr={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
     vector<vector<int>>vr={{1,2,3},{4,5,6},{7,8,9}};
    solve(vr);
    
    for (int i = 0; i <vr.size(); i++)
    {
        for (int j = 0; j <vr[i].size(); j++)
        {
            cout<<vr[i][j]<<" ";
        }

        cout<<endl;
        
    }
    
    return 0;
}