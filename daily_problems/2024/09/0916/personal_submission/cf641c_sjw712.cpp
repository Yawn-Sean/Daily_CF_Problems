void solve(){
	int n, q;
	cin >> n >> q;
	int odd = 0, even = 0, flag = 0;
	while(q --){
		int op;
		cin >> op;
		if(op == 1){
			int x;
			cin >> x;
			odd += x;
			even += x;
			flag ^= x & 1;
		}
		else{
			if(flag){
				even += 1;
				odd -= 1;
			}
			else {
				even -= 1;
				odd += 1;
			}
			flag ^= 1;
		}
	}
	vector<int> ans(n);
	int mod = n;
	for(int i = 0; i < n; i ++){
		if(i & 1){
			ans[((i + even) % mod + mod) % mod] = i + 1;
		}
		else{
			ans[((i + odd) % mod + mod) % mod] = i + 1;
		}
	}
	for(int i = 0; i < n; i ++) cout << ans[i] << ' ';
}
