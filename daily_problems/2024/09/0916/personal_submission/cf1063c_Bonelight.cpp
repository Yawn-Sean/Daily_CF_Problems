#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
// #define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n; cin >> n;
    auto query = [&](int x, int y){
        n --;
        cout << x << ' ' << y << endl;
        string res; cin >> res;
        // return (res == "1"? 1 : 0);
        return (res == "black"? 1 : 0);
    };

    int l = 0, r = 1e9;
    bool st = query(r, r);

    while(n){
        int mid = l + r >> 1;
        if(query(mid, mid) == st) r = mid;
        else l = mid;
    }

    cout << l << ' ' << r << ' ' << r << ' ' << l;
}  

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
