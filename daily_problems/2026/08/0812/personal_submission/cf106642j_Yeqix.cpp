#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

template <class T, class Cmp = std::less<T>>
class RMQ {
	const int n;
	const int logn;

	const Cmp cmp = Cmp();
	std::vector<std::vector<T>> jump;
public:
	RMQ(const std::vector<T> &a)
		: n(a.size()), logn{std::__lg(n)}, jump(logn + 1) {

		jump[0] = a;

		for (int j = 1; j <= logn; j++) {
			jump[j].resize(n - (1 << j) + 1);
		}

		for (int j = 0; j < logn; j++) {
			const int limit = n - (1 << (j + 1));
			for (int i = 0; i <= limit; i++) {
				jump[j + 1][i] = std::min(jump[j][i], jump[j][i + (1 << j)], cmp);
			}
		}
	}

	// [l, r)
	constexpr T operator()(int l, int r) const {
		assert(l < r and r <= n);
		int log = std::__lg(r - l);
		return std::min(jump[log][l], jump[log][r - (1 << log)], cmp);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<vector<i64>> fc(n + 1, {0});
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		fc[a[i]].push_back(i);
	}

	RMQ st(a);

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		int len = fc[i].size();
		if (len == 1) {
			continue;
		}
		vector<vector<i64>> pre(2, vector<i64>(len));
		for (int j = 1; j < len; j++) {
			pre[0][j] = pre[0][j - 1], pre[1][j] = pre[1][j - 1];
			pre[j & 1][j] += fc[i][j] - fc[i][j - 1];
		}
		for (int j = 1; j < len; j++) {
			int l = 1, r = fc[i][j];
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (st(mid, fc[i][j] + 1) == i) {
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}

			int v = lower_bound(fc[i].begin(), fc[i].end(), l) - fc[i].begin();
			i64 res = -((v & 1) == (j & 1)) * (l - fc[i][v - 1] - 1);
			v += ((v & 1) != (j & 1));
			res += pre[j & 1][j] - pre[v & 1][v - 1];
			l = fc[i][j], r = (j != len - 1 ? fc[i][j + 1] - 1 : n);
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (st(fc[i][j], mid + 1) == i) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}

			ans += res * (r - fc[i][j] + 1);
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}