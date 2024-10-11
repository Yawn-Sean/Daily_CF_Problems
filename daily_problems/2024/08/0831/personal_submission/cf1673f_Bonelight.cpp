#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define endl '\n'
#define pii pair<int, int>
 


void solve()
{
    int n,q; cin >> n >> q;

    vector<int> b = {0};
    for(int i = 0; i < 5; i ++){
        for(int j = (1 << i) - 1; j >= 0; j --){
            b.push_back(b[j] | (1 << 2 * i));
        }
    }
    
    vector<pii> table(32 * 32);
    for(int i = 0; i < 32; i ++){
        for(int j = 0; j < 32; j ++){
            table[ b[i] ^ (b[j] * 2) ] = {i + 1, j + 1};
        }
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - 1; j ++){
            cout << (b[j] ^ b[j + 1]) * 2 << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < n - 1; i ++){
        for(int j = 0; j < n; j ++){
            cout << (b[i] ^ b[i + 1]) << ' ';
        }
        cout << endl;
    }
    cout << endl;

    int now = 0;
    while(q --){
        int op; cin >> op;
        now ^= op;
        auto [x,y] = table[now];
        cout << x << " " << y <<endl;
    }
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
