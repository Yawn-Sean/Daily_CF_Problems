void solve(){
	int n;
	cin >> n;
	vector<int> y(n + 1);
	
	for(int i = 1; i <= n; i ++) cin >> y[i];
	auto check = [&](int i, int j)->bool{
		vector<bool> st(n + 1);
		for(int k = 1; k <= n; k ++){
			if((j - i) * y[k] == (y[j] - y[i]) * k + j * y[i] - i * y[j]) st[k] = true;
		}
		if(count(st.begin() + 1, st.end(), 1) == n) return false;
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
		bool ok = true;
		for(int k = 1; k <= n; k ++){
			if(!st[k]){
				if(x1 == -1){
					x1 = k, y1 = y[k];
				}
				else if(x2 == -1){
					x2 = k, y2 = y[k];
					if((y[j] - y[i]) * (x2 - x1) != (y2 - y1) * (j - i)){
						ok = false;
						break;
					}
				}
				else{
					if((x2 - x1) * y[k] != (y2 - y1) * k + x2 * y1 - x1 * y2){
						ok = false;
						break;
					}
				}
			}
		}
		return ok;
	};
	if(check(1, 2)) return cout << "Yes" << '\n', void();
	if(check(1, 3)) return cout << "Yes" << '\n', void();
	if(check(2, 3)) return cout << "Yes" << '\n', void();
	cout << "No" << '\n';
}
