#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10,INF = 0x3f3f3f3f3f3f3f3f;

int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}

void solve()
{
    int n,k,a,b;cin >> n >> k >> a >> b;
    int a1 = a,a2 = k-a;
    int mi = INF,mx = 0;
    for(int i = 0;i<=n;i++)
    {
        int b1 = i*k+b,b2 = i*k-b;
        int blist[] = {b1,b2};
        for(int j = 0;j<=1;j++)
        {
            int l = abs(a-blist[j]),l1 = abs(a1-blist[j]);
            int ans = n*k/gcd(n*k,l),ans1 = n*k/gcd(n*k,l1);
            mi = min(mi,min(ans,ans1));
            mx = max(mx,max(ans,ans1));
        }
    }

    cout << mi << ' ' << mx << endl;


}

signed main()
{
    IOS
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
