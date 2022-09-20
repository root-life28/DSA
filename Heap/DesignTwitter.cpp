#include<bits/stdc++.h>
using namespace std;

class Twitter
{
    private:
    int count;
    priority_queue<vector<int>>pq;
    unordered_map<int,set<int>>follower;
    public:

    Twitter() {
        count=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        pq.push({count,userId,tweetId});
      
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int>res;
        set<int>st=follower[userId];

        priority_queue<vector<int>>temp=pq;

        int x=0;
        while (x!=10&&!temp.empty())
        {
            vector<int>vr=temp.top();
            temp.pop();
            if(st.find(vr[1])!=st.end()||vr[1]==userId)
            {
                res.push_back(vr[2]);
                x++;
            }
        }
        
       return res;
    }
    
    void follow(int followerId, int followeeId) {

        follower[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }

  
};



int main()
{
    Twitter *obj=new Twitter();

    vector<int>vr;

   obj->postTweet(1,5);
   obj->postTweet(1,3);
   obj->postTweet(1,10);

   vr=obj->getNewsFeed(1);
   for(auto x:vr)cout<<x<<" ";
   cout<<endl;





    
    return 0;
}