void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	int p = 0, q, cur = 1;
	int tota = count(a.begin(), a.end(), 0);
	int totb = count(b.begin(), b.end(), 0);
	q = inv(qmi(m, tota + totb) % mod);
	for(int i = 0; i < n; i ++){
		if(a[i] == 0 && b[i]){
			p = (p + cur * (m - b[i]) % mod * qmi(m, tota + totb - 1) % mod) % mod;
			tota --;
		}
		else if(b[i] == 0 && a[i]){
			p = (p + cur * (a[i] - 1) % mod * qmi(m, tota + totb - 1) % mod) % mod;
			totb --;
		}
		else if(a[i] == 0 && b[i] == 0){
			p = (p + cur * m % mod * (m - 1) % mod * inv(2) % mod * qmi(m, tota + totb - 2)) % mod;
			tota --, totb --;
			cur = (cur * m) % mod;
		}
		else{
			if(a[i] < b[i]){
				break;
			}
			else if(a[i] > b[i]){
				p = (p + cur * qmi(m, tota + totb) % mod) % mod;
				break;
			}
		}
	}
	cout << p * q % mod << '\n';
}
