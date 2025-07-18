#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//模拟
void sol()
{
    int n;cin>>n;
    vector<pair<string,int>>ans;
    priority_queue<int,vector<int>,greater<int>>pq;//维护当前有的值
    for(int i=1;i<=n;++i)
    {
       string s;cin>>s;
       if(s=="insert")
       {
         int x;cin>>x;
         pq.push(x);
         ans.emplace_back("insert",x);
       }
       else if(s=="getMin")
       {
         int x;cin>>x;
         while(!pq.empty()&&pq.top()<x)
         {
            pq.pop();
            ans.emplace_back("removeMin",0);
         }
         if(pq.empty()||pq.top()!=x)
         {
            pq.push(x);
            ans.emplace_back("insert",x);
         }
         ans.emplace_back("getMin",x);
       }
       else
       {
         if(pq.empty())
         {
           pq.push(1);
           ans.emplace_back("insert",1);  
         }
         pq.pop();
         ans.emplace_back("removeMin",0);
       }
    }
    cout<<ans.size()<<endl;
    for(auto[x,y]:ans)
    {
        if(x=="removeMin")
        {
            cout<<x<<endl;
        }
        else cout<<x<<' '<<y<<endl;
    }
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
