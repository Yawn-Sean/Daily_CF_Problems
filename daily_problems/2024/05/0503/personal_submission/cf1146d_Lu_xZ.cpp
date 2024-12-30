#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5, inf = 0x3f3f3f3f;

int m, a, b;
int mi[N], v[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> m >> a >> b;
	
	memset(mi, 0x3f, sizeof mi);
	
	typedef pair<int, int> T;
	priority_queue<T, vector<T>, greater<T>> q;
	
	q.push({mi[0] = 0, 0});
	
	auto check = [&](int p) -> bool {
		return p >= 0 && p <= a + b;  
	};
	
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(v[x]) continue;
		v[x] = 1;
		for(auto y : {x + a, x - b}) {
			if(check(y) && mi[y] > max(mi[x], y)) {
				mi[y] = max(mi[x], y);
				q.push({mi[y], y});
			}
		}
	}
	ll ans = 0;
	
	for(int i = 0; i <= a + b; ++ i) {
		if(mi[i] <= m) {
			ans += max(0, m - mi[i] + 1); 
		}
	}
	
	if(m > a + b) {
		for(int i = b + 1; i <= a + b; ++ i) {
			if(a + i > m) break;
			if(mi[i] <= m) {
				int st = a + i;
				int k = (m - st) / a; 
				ans += ll(m - st + 1) * (k + 1) -  k * ll(k + 1) / 2 * a;
			}
		}
	}
	cout << ans;
	return 0;
}
