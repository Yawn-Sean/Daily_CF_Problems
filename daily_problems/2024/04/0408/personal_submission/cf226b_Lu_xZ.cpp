#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 5;

ll n, m, k, a[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1, greater<ll>());
	ll res_1 = 0;
	for(int i = 1; i <= n; ++ i) res_1 += a[i] * (i - 1);
	for(int i = 1; i <= n; ++ i) a[i] += a[i - 1];
	
	cin >> m;
	while(m --) {
		cin >> k;
		if(k == 1) {
			cout << res_1 << '\n';
			continue;
		}
		ll ans = 0, i = 1, dep = 0, t = 1;
		while(i <= n) {
			int j = min(n, i + t - 1);
			ans += (a[j] - a[i - 1]) * dep ++;
			i = j + 1;
			t *= k;
		}
		cout << ans << ' ';
	}
	return 0;
}
