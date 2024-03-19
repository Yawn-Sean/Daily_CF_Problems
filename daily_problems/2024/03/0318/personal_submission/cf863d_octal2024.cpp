#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
inline void solve()
{
    int n, q, m;
    cin >> n >> q >> m;
    vector<array<int, 3>> qs(q+1);
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) 
        cin >> a[i];
    for(int i=1; i<=q; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        qs[i] = {op, l, r};
    }
    for(int i=1; i<=m; i++) {
        int x;
        cin >> x;
        for(int j=q; j>=1; j--) {
            auto [op, l, r] = qs[j];
            if(l <= x && x <= r) {
                if(op == 1) {
                    x --;
                    if(x == l-1) x = r;
                } else {
                    x = r-(x-l);
                }
            }
        }
        cout << a[x] << " ";
    }
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
