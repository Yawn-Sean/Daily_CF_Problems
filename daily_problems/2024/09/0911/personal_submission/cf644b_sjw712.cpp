void solve(){
	int n, b;
	cin >> n >> b;
	queue<int> q;
	for(int i = 1; i <= n; i ++){
		int t, d;
		cin >> t >> d;
		while(q.size() && q.front() <= t) q.pop();
		if(q.size() > b) cout << -1 << " ";
		else{
			if(q.size()) t = q.back();
			cout << t + d << " ";
			q.push(t + d);
		}
	}

}
