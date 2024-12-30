const int d = 3;
void solve(){
	int n;
	cin >> n;
	vector<vector<int>> p(n, vector<int>(d));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < d; j ++){
			cin >> p[i][j];
		}
	}
	auto work = [&](auto self, vector<int> idx, int k)->int{
		if(k == d) return idx[0];
		map<int, vector<int>> mp;
		for(auto i : idx){
			mp[p[i][k]].push_back(i);
		}
		vector<int> tmp;
		for(auto i : mp){
			auto cur = self(self, i.y, k + 1);
			if(cur != -1){
				tmp.push_back(cur);
			}
		}
		for(int i = 0; i + 1 < tmp.size(); i += 2){
			cout << tmp[i] + 1 << " " << tmp[i + 1] + 1 << '\n';
		}
		if(tmp.size() % 2 == 0) return -1;
		return tmp.back();
	};
	vector<int> id(n);
	for(int i = 0; i < n; i ++) id[i] = i;
	work(work, id, 0);
}
