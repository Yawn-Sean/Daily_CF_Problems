#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

int n, p, k, a[N];

void solve() {
	cin >> n >> p >> k;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	int sum = 0;
	for(int i = 0; i < k; ++ i) {
		sum += a[i];
		if(sum > p) {
			break;
		}
		int tmp = i, cur = sum;
		for(int j = i + k; j <= n; j += k) {
			cur += a[j];
			if(cur > p) break;
			tmp += k;
		}
		ans = max(ans, tmp);
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
