#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	double y1, y2, yw, xb, yb, r;
	cin >> y1>> y2 >> yw >> xb >> yb >> r;
	
	auto cal = [&](double a, double b, double c) {
		return (a * b) / (a + c);	
	};
	
	// (0, y1 + r) (xw, yw-r)
	auto dis = [&](double x0, double y0, double x1, double y1, double x2, double y2) {
		double k = (y2 - y1) / (x2 - x1);
		double dis = (x0 * k - y0 + y1) / sqrt(k * k + 1); 
		return fabs(dis);
	};
	
	// xb - xw / (yw - r) - yb = xw / (yw - r) - (y1 + r)
	// b - xw / c = xw / a
	// a(b-xw) = cxw
	// ab = (a+c)xw
	// xw = ab / (a+c)
	double xw = cal((yw - r) - (y1 + r), xb, (yw - r) - yb);
    double d = dis(0.0, y2, 0.0, y1 + r, xw, yw - r);
    if (d - r > 1e-9) {
    	cout << fixed << setprecision(10) << xw << '\n';
    } else {
    	cout << fixed << setprecision(10) << -1 << '\n';
    }
    
    return 0;
}
