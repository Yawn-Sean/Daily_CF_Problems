#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

int gcd(int a,int b)
{
    if(b==1)return a-b;
    if(a%b==0)return 0x3f3f3f3f3f3f3f3f;
    int res = a/b;
    res += gcd(b,a%b);
    return res;
}

void solve()
{
    int n;cin >> n;
    int ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = n;i>=1;i--)
    {
        ans = min(gcd(n,i),ans);
    }
    // cout << n << ' ';
    cout << ans << endl;
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
