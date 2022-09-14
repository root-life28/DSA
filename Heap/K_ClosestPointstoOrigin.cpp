#include<bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int>> pi;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
    vector<vector<int>>res;
    priority_queue<pi,vector<pi>,greater<pi>>pq;

    for (int i = 0; i < points.size(); i++)
    {
        int x=points[i][0];
        int y=points[i][1];
        int sq=pow((0-x),2)+pow((0-y),2);
        pq.push({sq,points[i]});
    }

    for (int i = 0; i < k; i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    

    return res;

}

int main()
{
    vector<vector<int>>points={{0,1},{1,0}};
    int k=2;

    vector<vector<int>>res;

    res=kClosest(points,k);

    for (int i = 0; i <res.size(); i++)
    {
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    


    return 0;
}