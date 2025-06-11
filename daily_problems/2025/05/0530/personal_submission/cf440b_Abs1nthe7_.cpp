#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//如何贪心的转移？
void sol()
{
   int n,sum=0;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;++i)cin>>a[i],sum+=a[i];
   int ne=sum/n;
   int ans=0;
   int lst=0;
   for(int i=0;i<n;++i)lst+=a[i]-ne,ans+=abs(lst);
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
