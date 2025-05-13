
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int > a(n, 0), b(n, 0);
	for(auto & c : a)
		cin >> c;
	for(int i = 0; i < n; i ++){
		int p = 1;
		while(a[p - 1]) 
			p ++;
		b[i] = p;
		a[p - 1] --;
		for(int j = 0; j < p - k; j ++)
			a[j] --;
	}
	for(auto c : b)
		cout << c <<' ';
	cout << endl;
}
