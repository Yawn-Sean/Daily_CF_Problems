#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int xx,yy,n;
    cin >> xx >> yy >> n;
    double x = xx / __gcd(xx,yy), y = yy / __gcd(xx,yy);
    
    auto equ = [&](double x, double y)->int{
        if(abs(x - y) < 1e-15) return 0ll;
        return (x > y? 1:-1); 
    };

    if(n >= y){
        cout << x << "/" << y << endl;
    } else {
        int ans1 = 1, ans2 = 1;
        double l = 0, r = 1;
        double diff = 1e18;
        for(int mom = 1; mom <= n; mom ++){
            while(equ((l + 1)/mom,x/y) < 0) l++;
            while(equ((r - 1)/mom,x/y) >= 0) r--;

            while(equ(r/mom, x/y) < 0) r ++;

            if(equ(abs(l/mom - x/y), diff) < 0){
                diff = abs(l/mom - x/y);
                ans1 = l, ans2 = mom;
            }
            if(equ(abs(r/mom - x/y), diff) < 0) {
                diff = abs(r/mom - x/y);
                ans1 = r, ans2 = mom;
            }
            // cout << fixed << setprecision(0) << l << ' ' << mom << endl; 
            // cout << fixed << setprecision(0) << r << ' ' << mom << endl; 
            // cout << fixed << setprecision(30) << diff << endl << endl;
        }
        cout << ans1 << '/' << ans2 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
}
