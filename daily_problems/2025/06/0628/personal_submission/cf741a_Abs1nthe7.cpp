#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//答案肯定在环上
//去遍历所有环，记录所有的环长度求lcm,不能成环直接-1
void sol()
{
   int n;cin>>n;
   vector<int>c(n+1);
   int ans=1;
   for(int i=1;i<=n;++i)cin>>c[i];
   vector<int>vis(n+1,0);
   for(int i=1;i<=n;++i)
   {
     if(!vis[i])
     {
        int nex=i;
        int o=0;
        while(!vis[nex])
        {
            vis[nex]=1;
            nex=c[nex];
            o++;
        }
        if(nex!=i)
        {
            cout<<-1<<endl;
            return;
        }
        if(o%2==0)o/=2;
        ans=ans*o/__gcd(ans,o);
     }
   }
   cout<<ans<<endl;
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
