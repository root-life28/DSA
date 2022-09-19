#include<bits/stdc++.h>
using namespace std;
int leastInterval(vector<char>& tasks, int n)
{
    vector<int>vr(26,0);
    for (int i = 0; i < tasks.size(); i++)
     vr[tasks[i]-65]++;

    priority_queue<int,vector<int>>pq;

    for (int i = 0; i < 26; i++)
    if(vr[i])pq.push(vr[i]);

    queue<pair<int,int>>q;
    int time=0;

    while (!pq.empty())
    {
        int x=pq.top();
        pq.pop();
        time++;
        if(x>1)q.push({x-1,time+n});

        auto y =q.front();

        if(y.second==time)
        {
            pq.push(y.first);
            q.pop();
        }

        if(pq.size()==0&&q.size())
        {
            while (y.second!=time)
            {
                time++;
            }
            
            pq.push(y.first);
            q.pop();
        }
    }
    
    

    return time;
    
}

// if(n==0) return tasks.size();
//         unordered_map<char,int>mp;
//         int count = 0;
//         for(auto e : tasks)
//         {
//             mp[e]++;
//             count = max(count, mp[e]);
//         }
        
//         int ans = (count-1)*(n+1);
//         for(auto e : mp) if(e.second == count) ans++;
//         return max((int)tasks.size(),ans);
int main()
{
    vector<char >tasks={'A','A','A','A','A','A','B','C','D','E','F','G'};
    int n=3;

   cout<< leastInterval(tasks,n);



    
    return 0;
}