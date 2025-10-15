#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//暴力直接去找到一个有解的方案
void sol()
{
    int n,a,b;cin>>n>>a>>b;
    int na,nb;
    for(int i=0;i<=n/a;++i)
    {
        if((n-a*i)%b==0)
        {
          int cur=1;
          int na=i;
          int nb=(n-a*i)/b;
          while(na--)
          {
            for(int i=1;i<a;++i)cout<<cur+i<<' ';
            cout<<cur<<' ';
            cur+=a;
          }
          while(nb--)
          {
            for(int i=1;i<b;++i)cout<<cur+i<<' ';
            cout<<cur<<' ';
            cur+=b;
          }
          return;
        }
    }
   cout<<-1<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    while(_--)sol();
    return 0;
}
