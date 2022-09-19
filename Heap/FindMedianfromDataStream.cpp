#include<bits/stdc++.h>
using namespace std;
class MedianFinder {

   
public:
    priority_queue<int,vector<int>>first;
    priority_queue<int,vector<int>,greater<int>>sec;
    int count;
    MedianFinder() {
        count=0;
    }
    
    void addNum(int num) {
     
        count++;
        if(count%2)
        {
            sec.push(num);
        }
        else first.push(num);
        
        if(sec.size()&&first.size())
        {
            int x=first.top();
            int y=sec.top();
            
            if(x>y)
            {
                first.pop();
                sec.pop();
                first.push(y);
                sec.push(x);
            }
        }
    }
    
    double findMedian() {
        double x;
        if(count%2)
        {
            x=sec.top();
        }
        else 
        {
            x=(first.top()+sec.top())*1.0/2;
        }
        
        return x;
    }
};


int main()
{
   
    
    return 0;
}