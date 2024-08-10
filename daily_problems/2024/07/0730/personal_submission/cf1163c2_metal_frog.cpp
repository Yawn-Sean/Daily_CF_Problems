#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	map<pii, unordered_set<ll>> lines;
	ll total = 0, res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
			int a = y1 - y2, b = x1 - x2;
			int d = __gcd(a, b); a /= d, b /= d;
			if (a < 0 || (a == 0 && b < 0)) {
			    a = -a;
			    b = -b;
			}
			ll c = 1LL * a * x1 - 1LL * b * y1;
			pii k = {a, b};
			if (!lines[k].count(c)) {
				total++;
				lines[k].insert(c);
				res += total - lines[k].size();
			}
		}
	}
	cout << res << "\n";
}
 
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
