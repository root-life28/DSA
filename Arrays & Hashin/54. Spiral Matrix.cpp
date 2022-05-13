#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<vector<int>>&matrix)
{
    vector<int> res;

    int top=0,down=matrix.size()-1;
    int left=0,right=matrix[0].size()-1;

    int D=0;

    while (top<=down&&left<=right)
    {
        if(D==0)
        {
            for (int i=left; i <=right; i++)
            {
                 res.push_back(matrix[top][i]);
                //cout<<matrix[top][i]<<" ";
            }
           // cout<<endl;

            top++;
        }
        else if(D==1)
        {
            for (int i =top; i <=down; i++)
            {
                res.push_back(matrix[i][right]);
                //cout<<matrix[i][right]<<" ";
            }
            //cout<<endl;
            right--;
            
        }
        else if(D==2)
        {
            for (int i =right; i>=left; i--)
            {
                res.push_back(matrix[down][i]);
               // cout<<matrix[down][i]<<" ";
            }
            down--;
            //cout<<endl;
        }
        else if(D==3)
        {
            for (int i =down; i>=top; i--)
            {
                res.push_back(matrix[i][left]);
                //cout<<matrix[i][left]<<" ";
            }

            //cout<<endl;
            left++;
            
        }
        D++,D%=4;
    }
    
  

    return res;
}

int main()
{
    vector<vector<int>>vr={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    //1 2 3 6 9 8 7 4 5

    vector<int>res=solve(vr);

    for (int i = 0; i <res.size(); i++)
    {
        cout<<res[i]<<" ";
        if(i>0&&i%3==0)cout<<endl;
        /* code */
    }
    
    return 0;
}