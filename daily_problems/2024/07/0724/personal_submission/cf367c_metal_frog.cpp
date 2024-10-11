#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<pii> mono(m);
    for (int i = 0; i < m; i++) {
        cin >> mono[i].second >> mono[i].first;
    }
    sort(all(mono));
    reverse(all(mono));

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ll tot;
        if (i % 2 == 1)
            tot = 1LL * (i + 1) * (i + 1) / 2;
        else
            tot = 1 + 1LL * i * (i + 1) / 2;
        if (tot > n) {
            break;
        }
        ans += mono[i].first;
    }
    if (n == 1) ans = mono[0].first;
    cout << ans << "\n";
}
