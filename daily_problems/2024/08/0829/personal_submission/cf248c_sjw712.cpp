void solve(){
	double y1, y2, yw, xb, yb, r;
	cin >> y1 >> y2 >> yw >> xb >> yb >> r;
	double a = yw - y1 - 2.0 * r, b = yw - yb - r;
	double x = a * xb / (a + b), l = sqrt(x * x + a * a);
	double ans =x * (y2 - y1 - r) / l;
	if(r > ans) cout << -1 << '\n';
	else cout << fixed << setprecision(10) << x << '\n';
}
