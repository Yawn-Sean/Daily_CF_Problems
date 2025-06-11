#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    int n; cin >> n;
    vector<int> fb(100);
    fb[0] = 1, fb[1] = 2;

    for(int i = 2; i < 100; i ++){
        fb[i] = fb[i - 1] + fb[i - 2];
    }

    for(int i = 0; i < 100; i ++){
        if(n < fb[i]){
            cout << i - 1 << endl;
            break;
        }
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
