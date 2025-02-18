#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

void solve()
{
    int a,b;cin >> a >> b;

    double ans = 0;
    if(b==0)ans = 1;
    else if(a==0)ans = 0.5;
    else if(a>=4*b)ans = 1.0*(2*b*(a-4*b)+(b+2*b)*2*b)/(2*a*b);
    else ans = (a*a+8*a*b)/(16*a*b*1.0);
    printf("%.10lf\n",ans);

}

signed main()
{
    IOS
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}
