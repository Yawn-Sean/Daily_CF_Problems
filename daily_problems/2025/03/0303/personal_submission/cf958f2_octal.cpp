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
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    int tot = 0;
    vector<int> b(m+1);
    for(int i=1; i<=m; i++)
        cin >> b[i], tot += b[i];
    vector<int> cnt(n+1);
    int res = 2e9;
    int t = tot;
    for(int l=1, r=1; l<=n; l++) {
        while(tot != 0 && r <= n) {
            if(cnt[a[r]] < b[a[r]]) tot --;
            cnt[a[r]] ++;
            r ++;
        }
        if(tot == 0)
            res = min(res, r-l-t);
        if(cnt[a[l]] <= b[a[l]]) tot ++;
        cnt[a[l]] --;
    }
    if(res == 2e9) cout << -1 << endl;
    else cout << res << endl;
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
