#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b);  --i)

constexpr int N = 200007;

ll a[N], b[N];

int main() {
    vector<pair<int, int>> s;
    int n = rd();
    rep(i, 1, n) {
        int x = rd(), y = rd();
        s.eb(x, y);
        ++a[x]; ++b[y];
    }
    ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (auto [x, y] : s) ans -= 1ll * (a[x] - 1) * (b[y] - 1);
    printf("%lld\n", ans);
    return 0;
}