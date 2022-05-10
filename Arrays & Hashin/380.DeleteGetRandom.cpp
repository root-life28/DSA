#include<bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    vector<int>vr;
   unordered_map<int,int>mp;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if(mp.find(val)==mp.end())
        {
            vr.emplace_back(val);
            mp[val]=vr.size()-1;
            return 1;
        }
        else return 0;
    }
    bool remove(int val) {

        if(mp.find(val)!=mp.end())
        {
            int temp=vr.back();
            int index=mp[val];
            mp[temp]=index;
           vr[index]=temp;
            vr.pop_back();
            mp.erase(val);
            return 1;
        }
        else return 0;
    }

    int getRandom()
    {   return vr[rand()%vr.size()];
    }
};


int main()
{
    RandomizedSet vr;
    vr.insert(2);
    vr.insert(3);
    cout<<vr.getRandom();
    vr.remove(2);

    return 0;
}