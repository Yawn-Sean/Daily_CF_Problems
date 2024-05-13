#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

struct Data {
	int l, d, r, u;
};

void solve() {
	int n; cin >> n;
	vector<int> pre_l, pre_d, pre_r, pre_u;
	vector<int> suf_l(n + 1), suf_d(n + 1), suf_r(n + 1), suf_u(n + 1);
	vector<Data> arr(n);

	pre_l.emplace_back(INT_MIN);
	pre_d.emplace_back(INT_MIN);
	pre_r.emplace_back(INT_MAX);
	pre_u.emplace_back(INT_MAX);

	suf_l[n] = INT_MIN;
	suf_d[n] = INT_MIN;
	suf_r[n] = INT_MAX;
	suf_u[n] = INT_MAX;

	for (int i = 0; i < n; i++) {
		int l, d, r, u; cin >> l >> d >> r >> u;
		arr[i].l = l, arr[i].d = d, arr[i].r = r, arr[i].u = u;
	}

	for (int i = 0; i < n; i++) {
		int l = arr[i].l, d = arr[i].d, r = arr[i].r, u = arr[i].u;
		pre_l.emplace_back(max(pre_l.back(), l));
		pre_d.emplace_back(max(pre_d.back(), d));
		pre_r.emplace_back(min(pre_r.back(), r));
		pre_u.emplace_back(min(pre_u.back(), u));
	}

	for (int i = n - 1; i >= 0; i--) {
		int l = arr[i].l, d = arr[i].d, r = arr[i].r, u = arr[i].u;
		suf_l[i] = max(suf_l[i + 1], l);
		suf_d[i] = max(suf_d[i + 1], d);
		suf_r[i] = min(suf_r[i + 1], r);
		suf_u[i] = min(suf_u[i + 1], u);
	}


	for (int i = 0; i < arr.size(); i++) {
		int l = max(pre_l[i], suf_l[i + 1]);
		int d = max(pre_d[i], suf_d[i + 1]);
		int r = min(pre_r[i], suf_r[i + 1]);
		int u = min(pre_u[i], suf_u[i + 1]);
		if (l <= r && d <= u) {
			cout << l << " " << u << endl;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; t = 1;
	while (t--) solve();
	return 0;
}
