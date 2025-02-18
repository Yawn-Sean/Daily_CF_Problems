vector<int> minp;
set<int> primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.insert(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
void solve(){
	int n;
	cin >> n;
	sieve(n + 1);
	vector<int> a(n + 1), b(n + 1);
	vector<pii> ans;
	map<int, int> mp;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		mp[a[i]] = i;
		b[i] = a[i];
	}
	sort(a.begin() + 1, a.end());
	auto myswap = [&](int i, int j)->void{
		swap(mp[b[i]], mp[b[j]]);
		swap(b[i], b[j]);
		ans.push_back({i, j});
	};
	for(int i = 1; i <= n; i ++){
		int j = mp[a[i]];
		if(i != j){
			if(j - i <= 5){
				for(int k = j; k >= i + 1; k--){
					myswap(k - 1, k);
				}
			}
			else{
				int k = j - i + 2;
				if(k % 2 == 1){
					myswap(j - 1, j);
					k --;
					j --;
				}
				for(auto p: primes){
					if(primes.count(k - p)){
						myswap(j - p + 1, j);
						myswap(i, j - p + 1);
						break;
					}
				}
			}
		}
	}
	cout << ans.size() << '\n';
	for(auto [i, j] : ans) cout << i << " " << j << '\n';
}
