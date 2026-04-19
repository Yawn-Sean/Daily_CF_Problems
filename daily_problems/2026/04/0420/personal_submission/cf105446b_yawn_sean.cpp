#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<double> acc_x(n + 1, 0), acc_y(n + 1, 0), acc_xy(n + 1, 0), acc_x2(n + 1, 0);

	for (int i = 0; i < n; i ++) {
		string sx, sy;
		cin >> sx >> sy;
		double x = stod(sx), y = stod(sy);

		acc_x[i + 1] = acc_x[i] + x;
		acc_y[i + 1] = acc_y[i] + y;
		acc_xy[i + 1] = acc_xy[i] + x * y;
		acc_x2[i + 1] = acc_x2[i] + x * x;
	}

	int q;
	cin >> q;

	cout << fixed << setprecision(10);

	while (q --) {
		int l, r;
		string s_lambda, s_x;
		cin >> l >> r >> s_lambda >> s_x; l --;
		double lambda = stod(s_lambda), x = stod(s_x);

		double vx = acc_x[r] - acc_x[l];
		double vy = acc_y[r] - acc_y[l];
		double vxy = acc_xy[r] - acc_xy[l];
		double vx2 = acc_x2[r] - acc_x2[l];

		double delta = (vx2 + lambda) * (r - l + lambda) - vx * vx;
		double k = ((r - l + lambda) * vxy - vx * vy) / delta;
		double b = ((vx2 + lambda) * vy - vx * vxy) / delta;

		cout << k * x + b << '\n';
	}

	return 0;
}