void solve(){
	int n;
	cin >> n;
	map<int, ordered_set> mp1, mp2;
	for(int i = 1; i <= n; i ++){
		int q, t, x;
		cin >> q >> t >> x;
		if(q == 1) mp1[x].insert(t);
		else if(q == 2) mp2[x].insert(t);
		else{
			auto it1 = mp1[x].upper_bound(t);
			if(mp1[x].size()) it1 --;
			auto it2 = mp2[x].upper_bound(t);
			if(mp2[x].size()) it2 --;
			if(it1 == mp1[x].end()){
				cout << 0 << '\n';
				continue;
			}
			int ans = mp1[x].order_of_key(*it1) + 1;
			if(it2 != mp2[x].end()) ans -= mp2[x].order_of_key(*it2) + 1;
			cout << ans << '\n';
		}
	}
}
