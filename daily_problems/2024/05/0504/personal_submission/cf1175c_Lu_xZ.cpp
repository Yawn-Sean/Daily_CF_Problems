#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

int n, a[N], k, ans, mi;

void solve() {
	cin >> n >> k;
	mi = 1e9;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if(i > k && mi > (a[i] - a[i - k] + 1) / 2) {
			mi = (a[i] - a[i - k] + 1) / 2;
			ans = a[i] + a[i - k] >> 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	
	while(T --) {
		solve();
	}
	return 0;
}
