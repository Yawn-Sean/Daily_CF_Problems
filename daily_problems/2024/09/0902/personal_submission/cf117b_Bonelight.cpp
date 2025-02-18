#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int a,b,mod; cin >> a >> b >> mod;
    int N = 1e9;
    N %= mod;
    int bottom = min(a, mod);
    
    int v = 0;
    for(int i = 1; i <= bottom; i ++){
        v = (v + N) % mod; 
        if(v + b < mod && v != 0) {
            string s = to_string(i);
            s = string(9 - s.size(), '0') + s;
            cout << "1 " << s << endl;
            return;
        }
    }
    cout << 2 << endl;

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
