const int mod = 1e9 + 7;
int qmi(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void solve(){
	int n;
	cin >> n;
	vector<pii> p(n);
	vector<int> h, v;
	for(int i = 0; i < n; i ++){
		int x, y;
		cin >> x >> y;
		p[i] = {x, y};
		h.push_back(x);
		v.push_back(y);
	}
	sort(h.begin(), h.end());
	sort(v.begin(), v.end());
	h.erase(unique(h.begin(), h.end()), h.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int k = h.size();
	auto get1 = [&](int x)->int{
		return lower_bound(h.begin(), h.end(), x) - h.begin() + 1;
	};
	auto get2 = [&](int x)->int{
		return k + lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
	};
	int m = k + v.size();
	vector<int> f(m + 1), cnt(m + 1), sz(m + 1);
	for(int i = 1; i <= m; i ++) f[i] = i, sz[i] = 1;
	auto find = [&](auto self, int x)->int{
		return x == f[x] ? x : f[x] = self(self, f[x]);
	};
	for(int i = 0; i < n; i ++){
		int x = find(find, get1(p[i].x)), y = find(find, get2(p[i].y));
		if(x != y){
			f[x] = y;
			sz[y] += sz[x];
			cnt[y] += cnt[x] + 1;
		}
		else{
			cnt[y] ++;
		}
	}
	int ans = 1;
	for(int i = 1; i <= m; i ++){
		if(f[i] == i){
			if(cnt[i] == sz[i] - 1) ans = (ans * (qmi(2, sz[i]) - 1) % mod + mod) % mod;
			else ans = (ans * qmi(2, sz[i]) % mod + mod) % mod;
		}
	}
	cout << ans << '\n';
}
