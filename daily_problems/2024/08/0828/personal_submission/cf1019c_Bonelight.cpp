#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define endl '\n'
#define pii pair<int, int>
 
void solve()
{

    int n; cin >> n;
/////
    auto q = [&](int x){
        cout << "? " << x << endl << endl;
        int r1; cin >> r1;
        cout << "? " << x + n / 2 << endl << endl;
        int r2; cin >> r2;

        if(r1 == r2) return 0;
        else if(r1 > r2) return 1;
        else return -1;
    };
    auto answer = [&](int x){
        cout << "! " << x << endl;
    };
/////
    if(n % 4 != 0) {answer(-1); return;}

    int l = 1, r = n / 2;
    int sign = q(1);
    if(sign == 0) {answer(1); return;}

    while(l < r) {
        int mid = l + r >> 1;
        int v = q(mid);
        if(v == 0) {answer(mid); return;}
        else if(v * sign < 0) r = mid;
        else l = mid + 1;
    }
    answer(l);
}
 
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
