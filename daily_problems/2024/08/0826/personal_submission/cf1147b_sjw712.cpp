void solve(){
	int n, m;
	cin >> n >> m;
	vector<unordered_set<int>> v(n);
	unordered_set<int> d;
	for(int i = 1; i <= n / i; i ++){
		if(n % i == 0){
			d.insert(i);
			if(i != n / i && i != 1) d.insert(n / i);
		}
	}
	for(int i = 1; i <= m; i ++){
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		if(b - a < a + n - b) v[b - a].insert(a);
		else v[a + n - b].insert(b);
	}
	auto check = [&](unordered_set<int> a, int k)->bool{
		vector<int> tmp;
		for(auto i : d){
			unordered_set<int> se;
			bool ok = true;
			for(auto j : a){
				if(!se.count(j)){
					while(!se.count(j)){
						if(a.count(j)){
							se.insert(j);
							j = (j + i) % n;
							if(j == 0) j = n;
						}
						else{
							ok = false;
							break;
						}
					}
				}
				if(!ok) break;
			}
			if(!ok) tmp.push_back(i);
		}
		for(auto i : tmp){
			if(n % 2 == 0 && k == n / 2) continue;
			d.erase(i);
		}
		return d.size() > 0;
	};
	for(int i = 0; i < v.size(); i ++){
		if(v[i].size()){
			if(!check(v[i], i)) return cout << "No" << '\n', void();
		}
	}
	cout << "Yes" << '\n';
}
