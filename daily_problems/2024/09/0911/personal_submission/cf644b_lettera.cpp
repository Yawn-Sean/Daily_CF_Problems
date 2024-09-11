#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define int ll
//const int mod=0?0:1e9+7
void solve()
{
    int  n,b;
    cin>>n>>b;
    vector<int>t(n),d(n),ans(n,-1);
    for(int i=0;i<n;i++)
        {
            cin>>t[i]>>d[i];
        }
    int cur=0,cnt=0,endtime=0;
    deque<int>end;
    for(int i=0;i<n;i++)
        {
         while(end.size()&&end.front()<=t[i])
             {
                 end.pop_front();
             }
            if(end.size()<=b)
            {
                 
                endtime=max(endtime,t[i])+d[i];
                end.push_back(endtime);
                ans[i]=endtime;
            }
        }
    for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" \n"[i==n-1];
        }
}
signed main()
{
    int t;
    t=1;
    while(t--)
    {	solve();
        }
    return 0;
}
