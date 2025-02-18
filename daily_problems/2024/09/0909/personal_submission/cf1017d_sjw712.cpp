const int N = 1 << 12;
int tr[N][110];
int lowbit(int x){
	return x & -x;
}
void add(int id, int x, int v){
	for(int i = x; i <= 101; i += lowbit(i)){
		tr[id][i] += v;
	}
}
int query(int id, int x){
	int res = 0;
	for(int i = x; i; i -= lowbit(i)){
		res += tr[id][i];
	}
	return res;
}
void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> w(n);
	for(int i = 0; i < n; i ++) cin >> w[i];
	auto get = [](string s) -> int{
		int res = 0;
		int n = s.size();
		for(int i = 0; i < n; i ++){
			res += ((s[i] - '0') << (n - i - 1));
		}
		return res;
	};
	vector<int> cnt(1 << n);
	for(int i = 0; i < m; i ++){
		string s;
		cin >> s;
		cnt[get(s)] ++;
	}
	vector<int> f(1 << n);
	for(int i = 0; i < (1 << n); i ++){
		for(int j = 0; j < n; j ++){
			if((i >> j & 1) == 0){
				f[i] += w[n - j - 1];
			}
		}	
	}
	for(int i = 0; i < (1 << n); i ++){
		for(int j = 0; j < (1 << n); j ++){
			if(cnt[j]){
				add(i, f[i ^ j] + 1, cnt[j]);
			}
		}
	}
	while(q --){
		string t;
		int k;
		cin >> t >> k;
		int x = get(t);
		cout << query(x, k + 1) << '\n';
	}
}
