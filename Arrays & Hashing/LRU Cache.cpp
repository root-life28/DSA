#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
struct Node{
    int key,value;
    Node *next;
    Node *prev;
    Node(int _key,int _value)
    {
        key=_key;
        value=_value;
    }
};

Node *head=new Node(0,0);
Node *tail=new Node(0,0);

int cap;
unordered_map<int,Node*>mp;
public:
    LRUCache(int capacity)
    {
            cap=capacity;
            head->next=tail;
            tail->prev=head;
    }
    void addNode(Node* newNode)
    {
        Node*temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node *delNode)
    {
        Node*delPrev=delNode->prev;
        Node*delNex=delNode->next;
        delPrev->next=delNex;
        delNex->prev=delPrev;
    }
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            Node*temp=mp[key];
            int ans=temp->value;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key]=head->next;
            return ans;
        }
        return -1;

    }
    void put(int key,int value)
    {
        if(mp.find(key)!=mp.end())
        {
            Node*temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }

        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key,value));
        mp[key]=head->next;

    }
};




int main()
{
  auto x= new LRUCache(3);
  x->put(1,1);
  x->put(2,2);
  cout<<x->get(1)<<endl;
  x->put(3,3);
  cout<<x->get(2)<<endl;
  x->put(4,4);
  cout<<x->get(1)<<endl;
  cout<<x->get(3)<<endl;
  cout<<x->get(4)<<endl;
    return 0;
}