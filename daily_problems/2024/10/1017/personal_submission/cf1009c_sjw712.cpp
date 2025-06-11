void solve(){
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for(int i = 1; i <= m; i ++){
		int x, d;
		cin >> x >> d;
		sum += x * n;
		if(d >= 0) sum += d * n * (n - 1) / 2;
		else{
			int k = n / 2;
			sum += d * k * (k + (n & 1));
		}
	}
	cout << fixed << setprecision(10) << (double)sum / n << '\n';
}
