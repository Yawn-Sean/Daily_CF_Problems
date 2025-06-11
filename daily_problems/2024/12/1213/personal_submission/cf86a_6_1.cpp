#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10,INF = 0x3f3f3f3f3f3f3f3f;

int cal(int c)
{
    int cc = c,cnt = 1;
    while(cc)
    {
        cc/=10;
        cnt*=10;
    }
    return c*(cnt-1-c);
}

void solve()
{
    int l,r;cin >> l >> r;
    int cntl = 0,cntr = 1;
    int ll = l,rr = r;
    while(rr)
    {
        rr/=10;
        cntr*=10;
    }
    int c = (cntr-1)/2;

    if(r<c)cout << cal(r) << endl;
    else if(l>c)cout << cal(l) << endl;
    else
    {
        cout << cal(c) << endl;
    }
    


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
