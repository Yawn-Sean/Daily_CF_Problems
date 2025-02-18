#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    int tot = 0;
    for(int i=1; i<=n; i++)
        tot += a[i][i];
    tot %= 2;
    int q;
    cin >> q;
    while(q --) {
        int op, x;
        cin >> op;
        if(op == 3) {
            cout << tot;
        } else {
            cin >> x;
            tot = 1 - tot;
        }
    }
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
