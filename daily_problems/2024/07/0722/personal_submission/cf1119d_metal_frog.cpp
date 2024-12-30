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

    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(all(s));
    int m = unique(all(s)) - s.begin();
    vector<ll> gap(m);
    for (int i = 1; i < m; i++) {
        gap[i] = s[i] - s[i - 1];
    }
    sort(gap.begin() + 1, gap.end());
    vector<ll> pref(m);
    for (int i = 1; i < m; i++) {
        pref[i] = pref[i - 1] + gap[i];
    }
    int q;
    cin >> q;
    while (q--) {
        ll L, R;
        cin >> L >> R;
        ll dis = R - L + 1;
        auto it = lower_bound(gap.begin() + 1, gap.end(), dis) - gap.begin();
        cout<< pref[it - 1] + dis * (m - it + 1) << " ";
    }
}

