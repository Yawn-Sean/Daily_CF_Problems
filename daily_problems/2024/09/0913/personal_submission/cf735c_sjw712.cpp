void solve(){
	int n;
	cin >> n;
	vector<int> f(1010);
	for(int k = 1; ; k ++){
		if(k == 1 || k == 2) f[k] = 1;
		else f[k] = f[k - 1] + f[k - 2];
		if(f[k] > n){
			cout << k - 3 << '\n';
			break;
		}
	}
}
