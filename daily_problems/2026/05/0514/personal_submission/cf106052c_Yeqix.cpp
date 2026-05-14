#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int N = 1e6;

vector<i64>phi(N + 1);
vector<i64> ans(N + 1);
vector<int>pri;
bitset<N>vis;

void get_phi() {
	phi[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!vis[i]) {
			pri.push_back(i);
			phi[i] = i - 1;
		}
		for (int j = 0; 1LL * pri[j] * i <= N; ++j) {
			int cur = i * pri[j];
			vis[cur] = 1;
			if (i % pri[j] == 0) {
				phi[cur] = phi[i] * pri[j];
				break;
			}
			phi[cur] = phi[i] * (pri[j] - 1);
		}
	}
	for (int i = 1; i <= N - 100; i++) {
		for (int j = i; j <= N - 100; j += i) {
			if (j / i & 1) {
				ans[j] += phi[j / i];
			}
		}
	}

	for (int i = 1; i <= N - 100; i++) {
		ans[i] = ans[i - 1] + ans[i] * 2 - 1;
	}
}

void solve() {
	int n;
	cin >> n;

	cout << ans[n] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	get_phi();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
