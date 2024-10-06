void solve(){
	int n;
	cin >> n;
	vector<pair<pii, int>> p(n);
	map<int, int> mp1, mp2;
	auto insert = [&](int h, int w, int id)->void{
		if(mp1.count(h)){
			if(mp1[h] > w){
				mp1[h] = w;
				mp2[h] = id;
			}
		}
		else{
			mp1[h] = w;
			mp2[h] = id;
		}
	};
	for(int i = 0; i < n; i ++){
		int h, w;
		cin >> h >> w;
		p[i] = {make_pair(h, w), i};
		insert(h, w, i + 1);
		insert(w, h, i + 1);
	}
	set<pii> s;
	vector<int> ans(n);
	sort(p.begin(), p.end(), [](pair<pii, int> a, pair<pii, int> b){
		return a.x < b.x;
	});
	auto it = mp1.begin();
	for(int i = 0; i < n; i ++){
		while(it->x < p[i].x.x && it != mp1.end()){
			s.insert({it->y, mp2[it->x]});
			++ it;
		}
		if(!s.size()){
			ans[p[i].y] = -1;
			continue;
		}
		auto k = *s.begin();
		if(k.x < p[i].x.y) ans[p[i].y] = k.y;
		else ans[p[i].y] = -1;

	}
	for(int i = 0; i < n; i ++) cout << ans[i] << " \n"[i == n - 1];
}
