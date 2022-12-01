#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>&hand,int groupSize)
{
    if(hand.size()%groupSize) return false;
    
    vector<bool>visit(hand.size()+1,false);
    sort(hand.begin(),hand.end());

    for (int i = 0; i <hand.size(); i++)
    {
        if(visit[i])continue;

        visit[i]=true;
        int cur=hand[i];
        int cnt=1;
        int j=i+1;
        while (j<hand.size()&&cnt<groupSize)
        {
            if(!visit[j]&&hand[j]==cur+1)
            {
                visit[j]=true;
                cnt++;
                cur=hand[j];
            }
            j++;
        }
        if(cnt!=groupSize) return false;

    }
    

    return true;
}
int main()
{
    vector<int>hand={1,2,3,6,2,3,4,7,8};
    int groupSize=3;
     cout<<solve(hand,groupSize);
    return 0;
}