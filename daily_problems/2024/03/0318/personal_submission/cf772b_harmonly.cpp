#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

struct P {
	ld x, y;
	P(){}
	P(ld x, ld y) : x(x), y(y) {}
	void read() { cin >> x >> y; }
	P operator + (P b) { return P{x + b.x, y + b.y}; }
	P operator - (P b) { return P{x - b.x, y - b.y}; }
	P operator * (ld mul) { return P{x * mul, y * mul}; }
	ld operator * (P b) { return x * b.y - y * b.x; }
	ld dot(P b) { return x * b.x + y * b.y; }
	ld len() { return sqrt(x * x + y * y); }
	P lenTo(ld to) { return *this * (to / len()); }
	ld dist(P &b) { return (*this - b).len(); }
};

ld f(P &a, P &b, P &c) {
	return fabs((b - a) * (b - c)) / a.dist(c);
}

void solve() {
	int n; cin >> n;
	vector<P> points(n + 2);
	for (int i = 0; i < n; ++i) {
		points[i].read();
	}
	points[n] = points[0];
	points[n + 1] = points[1];
	ld ans = 1e18;
	for (int i = 1; i < n + 2; ++i) {
		ans = min(ans, f(points[i - 1], points[i], points[i + 1]));
	}
	cout << fixed << setprecision(6) << ans * 0.5 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
