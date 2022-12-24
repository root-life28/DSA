#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string>tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    stack<int>st;
    int ans=0;
    for (int i = 0; i < tokens.size(); i++)
    {
           
          if(tokens[i]=="+")
            {
                
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                ans=b+a;
                st.push(ans);
            }
            else if(tokens[i]=="-")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                ans=b-a;
                st.push(ans);
            }
            else if(tokens[i]=="*")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                ans=a*b;
                st.push(ans);
            }
            else if(tokens[i]=="/")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                ans=b/a;
                st.push(ans);
            }
            else 
            {
                int x=stoi(tokens[i]);
                st.push(x);
            }
        
        
    }

    

    cout<<ans<<endl;
   
    return 0;
}