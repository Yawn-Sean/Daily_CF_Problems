map<char, int> mp = {{'|', 0}, {'&', 1}, {'^', 2}};
void solve(){
	int n;
	cin >> n;
	vector<pii> op(n);
	for(int i = 0; i < n; i ++){
		char a;
		int x;
		cin >> a >> x;
		op[i] = {mp[a], x};
	}
	vector<vector<int>> a(2, vector<int>(10));
	for(int i = 0; i < 2; i ++){
		for(int j = 0; j < 10; j ++){
			a[i][j] = i;
		}
	}
	for(int i = 0; i < 2; i ++){
		for(int j = 0; j < n; j ++){
			for(int k = 0; k < 10; k ++){
				if(op[j].x == 0){
					a[i][k] |= (op[j].y >> k & 1);
				}
				else if(op[j].x == 1){
					a[i][k] &= (op[j].y >> k & 1);
				}
				else{
					a[i][k] ^= (op[j].y >> k & 1);
				}
			}
		}
	}

	int b = 0, c = 1023, d = 0;
	for(int i = 0; i < 10; i ++){
		if(a[0][i] == 0 && a[1][i] == 1) continue;
		else if(a[0][i] == 0 && a[1][i] == 0){
			c -= (1 << i);
		}
		else if(a[0][i] == 1 && a[1][i] == 0){
			d |= (1 << i);
		}
		else{
			b |= (1 << i);
		}
	}
	cout << 3 << '\n';
	cout << "| " << b << '\n';
	if(c != -1) cout << "& " << c << '\n';
	cout << "^ " << d << '\n';
}
