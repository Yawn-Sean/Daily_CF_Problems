void solve(){
	int n;
	cin >> n;
	int l = 0, r = 1e9;
	auto ask = [&](int x)->bool{
		string res;
		cout << x << " " << 1 << endl;
		cin >> res;
		return res[0] == 'w';
	};
	bool last = ask(0);
	for(int i = 1; i <= n - 1; i ++){
		int mid = l + r >> 1;
		bool cur = ask(mid);
		if(cur == last) l = mid;
		else r = mid;
	}
	cout << l << " " << 0 << " " << l + 1 << " " << 2 << endl;
}
