#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void sol()
{
   int n;cin>>n;
   vector<vector<int>>a(n+1);
   for(int i=1;i<=n;++i)
    {
        int k;cin>>k;
        while(k--)
        {
            int x;cin>>x;
            a[i].push_back(x);
        }
        sort(a[i].begin(),a[i].end());
    }
    int ans=0;
    auto cacl=[&](vector<int>&a,int l,int r)->int
    {
        return lower_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l);
    };
    for(int i=1;i<=n;++i)
    {
        int lst=0;
       for(auto j:a[i])
       {
        if(lst==0)
        {
            lst=j;
            continue;
        }
        int now=j;
        if(i==1)ans+=(cacl(a[n],lst,now)!=cacl(a[i+1],lst,now));
        else if(i==n)ans+=(cacl(a[i-1],lst,now)!=cacl(a[1],lst,now));
        else ans+=(cacl(a[i-1],lst,now)!=cacl(a[i+1],lst,now));
        lst=now;
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
