const int mod = 998244353;
int qmi(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void add(int &a, int b){
	a += b;
	a %= mod;
}	
void solve(){
	int n;
	string s;
	cin >> n >> s;
	s = ' ' + s;
	int tot = count(s.begin(), s.end(), '?');
	vector<vector<int>> f(1 << 18, vector<int>(18));
	auto work = [&](int l, int r)->void{
		int cnt = tot, state = 0;
		while(l >= 1 && r <= n){
			if(s[l] != '?' && s[r] != '?' && s[l] != s[r]) break;
			if(s[l] == '?' && s[r] != '?') state |= (1 << (s[r] - 'a'));
			if(s[l] != '?' && s[r] == '?') state |= (1 << (s[l] - 'a'));
			if((s[l] == '?'|| s[r] == '?') && l != r) cnt --;
			for(int i = 1; i <= 17; i ++) add(f[state][i], qmi(i, cnt));
			l --, r ++;

		}
	};
	for(int i = 1; i <= n; i ++){
		work(i, i);
		work(i, i + 1);
	}
	for(int k = 1; k <= 17; k ++){
		for(int j = 0; j < 17; j ++){
			for(int i = 0; i < (1 << 17); i ++){
				if(i >> j & 1) add(f[i][k], f[i ^ (1 << j)][k]);
			}
		}
	}
	int q;
	cin >> q;
	while(q --){
		string t;
		cin >> t;
		int state = 0;
		for(int i = 0; i < t.size(); i ++){
			state |= (1 << (t[i] - 'a'));
		}
		cout << f[state][t.size()] << '\n';
	}
}
