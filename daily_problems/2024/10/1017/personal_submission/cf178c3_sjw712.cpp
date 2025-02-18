void solve(){
	int h, m, n;
	cin >> h >> m >> n;
	vector<int> group_id(h, -1), group_pos(h, -1);
	int cnt = 0, idx = 0;
	for(int i = 0; i < h; i ++){
		if(group_id[i] == -1){
			int j = i;
			idx = 0;
			while(group_id[j] == -1){
				group_id[j] = cnt;
				group_pos[j] = idx ++;
				j = (j + m) % h;
			}
			cnt ++;
		}
	}
	vector<set<int>> group(cnt);
	map<int, pii> mp;
	for(int i = 0; i < cnt; i ++){
		for(int j = 0; j < idx; j ++){
			group[i].insert(j);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		char op;
		int id, hash;
		cin >> op >> id;
		if(op == '+'){
			cin >> hash;
			int g_id = group_id[hash], pos = group_pos[hash];
			auto it = group[g_id].lower_bound(pos);
			if(it == group[g_id].end()) it = group[g_id].begin();
			if(*it < pos) ans += idx - pos + (*it);
			else ans += (*it) - pos;
			mp[id] = {(*it), g_id};
			group[g_id].erase((*it));
		}
		else{
			auto k = mp[id];
			group[k.y].insert(k.x);
		}
	}
	cout << ans << '\n';
}
