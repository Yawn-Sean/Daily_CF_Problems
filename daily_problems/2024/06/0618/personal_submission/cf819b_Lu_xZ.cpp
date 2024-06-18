#include<bits/stdc++.h>
#define ep emplace
using namespace std;

using pii = pair<int, int>;
using ll = long long;
constexpr int N = 1e6 + 5;

int n, k, a[N];
ll ans;
set<pii> se;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if(a[i] > i) {
			se.ep(a[i] - i, i);
		}
		ans += abs(i - a[i]);
	}
	ll tmp = ans;
	for(int i = n; i > 1; -- i) {
		int d = n - i + 1;
		auto x = make_pair(a[i] - i, i);
		if(se.count(x)) {
			se.erase(x);
		}
		tmp -= abs(a[i] - n);
		tmp += abs(a[i] - 1);
		
		tmp += (n - se.size() - 1) - se.size();
		
		if(a[i] > 1) {
			se.ep(a[i] - 1 + d, i);
		}
		while(!se.empty() && se.begin()->first == d) {
			se.erase(se.begin());
		}
		if(tmp < ans) {
			ans = tmp;
			k = d;
		}
	}
	cout << ans << ' ' << k;
	return 0;
}
