void solve(){
	int n;
	cin >> n;
	vector<int> a(n * 2 + 1);
	vector<int> d(n + 1);
	for(int i = 1; i <= n; i ++) d[i] = n - i;
	int cur1 = 1, cur2 = n + 1;
	for(int i = 1; i <= n; i ++){
		if(i & 1){
			a[cur1] = i;
			a[cur1 + d[i]] = i;
			cur1 ++;
		}
		else{
			a[cur2] = i;
			a[cur2 + d[i]] = i;
			cur2 ++;
		}
	}
	a[2 * n] = n;
	for(int i = 1; i <= 2 * n; i ++) cout << a[i] << " ";
}
