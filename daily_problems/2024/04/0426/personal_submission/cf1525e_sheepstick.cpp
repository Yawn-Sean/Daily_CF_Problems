//https://codeforces.com/contest/1525/submission/258174726

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < m; j++){
    		cin >> d[i][j];
    	}
    }
    Z res = 0;
    for (int j = 0; j < m; j++){
    	//earlist starting time s.t not covered
    	vector<int> cnt(n + 1, 0);
    	for (int i = 0; i < n; i++){
    		cnt[n - d[i][j] + 1]++;
    	}
    	if (cnt[n]){
    		res += 1;
    	}
    	else {
    		int space = 0;
    		Z cur = 1;
    		for (int i = n - 1; i >= 0; i--){
    			space++;
    			if (space < cnt[i]){
    				cur = 0;
    				break;
    			}
    			cur *= comb.binom(space, cnt[i]);
    			cur *= comb.fac(cnt[i]);
    			space -= cnt[i];
    		}
    		//cout << j << " "<< cur.val() << "----\n";
    		res += (comb.fac(n) - cur) / comb.fac(n);
    	}

    	//cout << j <<" "<< res.val() << "\n";
    }
    cout << res.val() << "\n";
}
