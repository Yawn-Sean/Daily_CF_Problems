#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 5;

ll n, A, cf, cm, m, a[N], b[N], c[N], suf[N], num, hight;
ll ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> A >> cf >> cm >> m;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	iota(c + 1, c + n + 1, 1);
	sort(c + 1, c + n + 1, [&](int i, int j) {
		return a[i] > a[j];
	});
	sort(a + 1, a + n + 1, greater<ll>());
	for(int i = n; i >= 1; -- i) {
		suf[i] = a[i] + suf[i + 1];
	}
	for(int i = 0; i <= n; ++ i) {
		if(i) m -= A - a[i];
		if(m < 0) break;
		ll l = a[n], r = A;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			int p = upper_bound(a + i + 1, a + n + 1, mid, greater<ll>()) - a;
			ll cnt = n - p + 1;
			if(mid * cnt - suf[p] <= m) l = mid;
			else r = mid - 1;
		}
		ll cur = i * cf + l * cm;
		if(ans < cur) {
			ans = cur;
			num = i, hight = l;
		}
	}
	for(int i = 1; i <= num; ++ i) b[c[i]] = A;
	for(int i = num + 1; i <= n; ++ i)  b[c[i]] = max(a[i], hight);
	cout << ans << '\n';
	for(int i = 1; i <= n; ++ i) cout << b[i] << ' ';
	return 0;
}
