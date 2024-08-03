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
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n);
	vector<PII> st;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) {
		int t, r; cin >> t >> r;
		while (st.size() && st.back().second <= r) st.pop_back();
		st.push_back({ t, r });
	}
	st.push_back({ 1, 0 });
	vector<int> b(a);
	sort(b.begin(), b.begin() + st[0].second);
	int l = 0, r = st[0].second - 1;
	for (int i = 0; i < st.size() - 1; i++) {
		for (int j = st[i].second; j > st[i + 1].second; j--) {
			a[j - 1] = st[i].first == 2 ? b[l++] : b[r--];
		}
	}
	for (auto& x : a) cout << x << " ";
	cout << endl;
	return 0;
}
