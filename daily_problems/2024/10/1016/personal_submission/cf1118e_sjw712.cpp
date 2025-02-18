void solve(){
	int n, m;
	cin >> n >> m;
	if(n > m * (m - 1)) return cout << "NO" << '\n', void();
	cout << "YES" << '\n';
	for(int j = 3; j <= 2 * m - 1; j ++){
		for(int k = min(j - 1, m); k >= max(1ll, j - m); k --){
			if(j == 2 * k) continue;
			cout << k << " " << j - k << '\n';
			n --;
			if(!n) return; 
		}
	}
}
