#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
using namespace std;

using pii = pair<int, int>;
using ll = long long;
constexpr int N = 2e5 + 5;

int n, k, a[N], idx;
vector<pii> ql[N];

set<pii, greater<pii>> se;
set<pii> ss;
void erase(pii x) {
	se.erase(x), ss.erase(x);
}
void insert(pii x) {
	se.insert(x), ss.insert(x);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		int l, r; cin >> l >> r;
		ql[l].eb(r, i);
	}
	for(int i = 1; i < N; ++ i) {
		while(!ss.empty() && ss.begin()->first < i) {
			erase(*ss.begin());
		}
		for(auto [r, id] : ql[i]) {
			insert({r, id});
		}
		while(se.size() > k) {
			auto x = *se.begin();
			erase(x);
			a[++ idx] = x.second;
		}
	}
	cout << idx << '\n';
	for(int i = 1; i <= idx; ++ i) {
		cout << a[i] << ' ';
	}
	return 0;
}
