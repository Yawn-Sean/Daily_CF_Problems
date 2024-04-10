#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5;

int n, m, a[N], b[N];
ll ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; ++ i) cin >> a[i];
	for(int i = 0; i < m; ++ i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m, greater<ll>());
	for(int i = 0; i < min(n, m) && b[i] > a[i]; ++ i) ans += b[i] - a[i];
	cout << ans;
	return 0;
}
