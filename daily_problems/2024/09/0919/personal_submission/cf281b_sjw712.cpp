struct num{
	int p, q;
	num(int _p, int _q){
		p = _p, q = _q;
	}
	bool operator<(num & t) const{
		return p * t.q < t.p * q;
	}
};
void solve(){
	int x, y, n;
	cin >> x >> y >> n;
	num mn(-1, -1);
	int a, b;
	for(int bb = 1; bb <= n; bb ++){
		int res = 1e18, aa;
		for(int i = bb * x / y - 1; i <= bb * x / y + 1; i ++){
			if(abs(bb * x - i * y) < res){
				res = abs(bb * x - i * y);
				aa = i;
			}
		}
		if(mn.p == -1){
			mn = num(res, bb * y);
			a = aa, b = bb;
		}
		else if(num(res, bb * y) < mn){
			mn = num(res, bb * y);
			a = aa, b = bb;
		}
	}
	cout << a << "/" << b << '\n';
}
