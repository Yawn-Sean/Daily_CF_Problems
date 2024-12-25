#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

void solve()
{
    int n,m;cin >> n >> m;
    if(m>n)swap(m,n);
    if(n==1||m==1)cout << max(n,m) << endl;
    else if(n==2||m==2)cout <<  n-n%4+2*min(n%4,2ll);
    else cout <<(n*m+1)/2;
    // else cout << max(n*((m+2)/3),m*((n+2)/3));
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
