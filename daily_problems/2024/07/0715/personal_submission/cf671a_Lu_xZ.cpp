#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
using namespace std;

using ll = long long;
using db = double;
constexpr int N = 1e5 + 5;

struct Node {
	int x, y, id;
	Node(int x = 0, int y = 0) 
		: x(x), y(y) {}
};
istream& operator >> (istream &in, Node &a) {
	in >> a.x >> a.y;
	return in;
}
inline ll sq(ll x) {
	return x * x;
}
inline db D(const Node &a, const Node &b) {
	return sqrt(sq(a.x - b.x) + sq(a.y - b.y)); 
}
int n;
Node a, b, t, c[N], d[N];
db ans = 1e18;

int main() {
	cin.tie(0)->sync_with_stdio(0), cout << fixed << setprecision(12);
	cin >> a >> b >> t;
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> c[i];
		c[i].id = i, d[i] = c[i];
	}
	if(n == 1) {
		cout << min(D(c[1], a), D(c[1], b)) + D(c[1], t);
		exit(0);
	}
	sort(d + 1, d + n + 1, [&](auto &x, auto &y) {
		return D(a, x) - D(t, x) < D(a, y) - D(t, y);
	});
	db x = D(a, d[1]) + D(d[1], t);
	for(int i = 2; i <= n; ++ i) {
		x += 2 * D(t, d[i]);
	}
	ans = min(ans, x);
	int ai = d[1].id, aj = d[2].id;
	
	sort(d + 1, d + n + 1, [&](auto &x, auto &y) {
		return D(b, x) - D(t, x) < D(b, y) - D(t, y);
	});
	x = D(b, d[1]) + D(d[1], t);
	for(int i = 2; i <= n; ++ i) {
		x += 2 * D(t, d[i]);
	}
	ans = min(ans, x);
	int bi = d[1].id, bj = d[2].id;
	
	
	if(ai != bi) {
		x = D(a, c[ai]) + D(c[ai], t) + D(b, c[bi]) + D(c[bi], t);
		for(int i = 1; i <= n; ++ i) {
			if(i != ai && i != bi)
				x += 2 * D(c[i], t);
		}
		ans = min(ans, x);
	}
	else {
		x = D(a, c[ai]) + D(c[ai], t) + D(b, c[bj]) + D(c[bj], t);
		for(int i = 1; i <= n; ++ i) {
			if(i != ai && i != bj)
				x += 2 * D(c[i], t);
		}
		ans = min(ans, x);
		x = D(a, c[aj]) + D(c[aj], t) + D(b, c[bi]) + D(c[bi], t);
		for(int i = 1; i <= n; ++ i) {
			if(i != aj && i != bi)
				x += 2 * D(c[i], t);
		}
		ans = min(ans, x);
	}
	cout << ans;
	return 0;
}
