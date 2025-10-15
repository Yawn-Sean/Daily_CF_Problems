#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

int a[N],b[N];


void solve()
{
    int n,m,w;cin >> n >> m >> w;
    for(int i = 1;i<=n;i++)cin >> a[i];
    for(int i = 1;i<=m;i++)cin >> b[i];

    sort(a+1,a+1+n,greater<>()),sort(b+1,b+1+m,greater<>());
    for(int i = 1;i<=n;i++)
    {
        auto it = upper_bound(b+1,b+1+m,a[i],greater<>())-b-1;
        if((w+1)*i+n-i-(w+1)*it-(m-it)>0ll){cout << "YES\n";return;}
    }
    auto it = upper_bound(b+1,b+1+m,4,greater<>())-b-1;
    cout << "NO\n";
}

signed main()
{
    IOS
    int tt = 1;

    while(tt--)
    {
        solve();
    }
    return 0;
}
