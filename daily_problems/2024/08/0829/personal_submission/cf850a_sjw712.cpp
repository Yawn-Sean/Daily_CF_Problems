struct Point{
	int a, b, c, d, e;
};
int cross(const Point& x, const Point& y){
	return x.a * y.a + x.b * y.b + x.c * y.c + x.d * y.d + x.e * y.e; 
}
Point vec(const Point& x, const Point& y){
	return Point{y.a - x.a, y.b - x.b, y.c - x.c, y.d - x.d, y.e - x.e};
}
void solve(){
	int n;
	cin >> n;
	vector<Point> p(n + 1);
	vector<int> ans;
	for(int i = 1; i <= n; i ++){
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		p[i] = {a, b, c, d, e};
	}
	if(n > 11) return cout << 0 << '\n', void();
	for(int i = 1; i <= n; i ++){
		bool ok = true;
		for(int j = 1; j <= n; j ++){
			for(int k = 1; k <= n; k ++){
				if(j == i || j == k || k == i) continue;
				Point x = vec(p[i], p[j]), y = vec(p[i], p[k]);
				int res = cross(x, y);
				if(res > 0){
					ok = false;
					break;
				}
			}
			if(!ok) break;
		}
		if(ok) ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i << '\n';
}
