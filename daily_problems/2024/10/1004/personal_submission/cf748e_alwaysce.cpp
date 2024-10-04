#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, k;
	cin >> n >> k;
	
	int M = 1e7;
	vector<i64> cnt(M + 1);	
	vector<int> a(n);
	for (auto& x: a) { cin >> x; cnt[x]++; }
	
	i64 cur = 0;
	for (int i = M; i > 0; i--) {
		cur += cnt[i];
		if (i * 2 + 1 <= M) {
			cur += cnt[i * 2 + 1];
			cnt[i] += cnt[i * 2 + 1];
			cnt[i + 1] += cnt[i * 2 + 1];
		}
		if (i * 2 <= M) {
			cur += cnt[i * 2];
			cnt[i] += cnt[i * 2] * 2;
		}
		if (cur >= k) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
