#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int cala(int x)
{
    int res=0;
    while(x)
    {
        res++;
        x/=10;
    }
    return res;
}
void sol()
{
   int w,m,k;
   cin>>w>>m>>k;
   w/=k;
   int _max=10,digit=1,ans=0;
   while(1)
   {
     int now=max(0ll,_max-m);
     if(now*digit<=w)
     {
        w-=now*digit;
        ans+=now;
        m+=now;
     }
     else
     {
        ans+=w/digit;
        cout<<ans<<endl;
        return;
     }
     digit++;_max*=10;
   }
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
