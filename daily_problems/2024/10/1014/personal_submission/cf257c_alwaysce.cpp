#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const double PI = acos(-1.0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<double> xs(n), ys(n);
	for (int i = 0; i < n; i++) {
		cin >> xs[i] >> ys[i];
	}
	
	auto get_angle = [&](double x, double y) {
		double angle = atan2(y, x) * 180.0 / PI;
		if (angle < 0) {
			angle += 360.0;
		}
		return angle;
	};
	
	vector<double> angles;
	for (int i = 0; i < n; i++) {
		angles.push_back(get_angle(xs[i], ys[i]));
	}
	
	sort(angles.begin(), angles.end());
	double max_gap = 0.0;
	for (int i = 0; i < n; i++) {
		double tmp;
		if (i == n - 1) {
			tmp = (angles[0] + 360.0) - angles[i];
		} else {
			tmp = angles[i + 1] - angles[i];
		}
		max_gap = max(max_gap, tmp);
	}
	
	double ans = 360.0 - max_gap;
	cout << fixed << setprecision(10) << ans;
    return 0;
}
