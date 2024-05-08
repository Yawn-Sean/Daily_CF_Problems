inline void solve(){
	// 详细地址 : https://codeforces.com/contest/1102/submission/259938745 
	int n ; cin >> n ; 
	vector<int> a(n+1) ; vector<PII> b; set<int> st ; map<int,vector<int>> mp ;
	for(int i=1;i<=n;i++) cin >> a[i] ,mp[a[i]].push_back(i) ;
	for(int i=1;i<=n;i++){
		if(st.count(a[i])) continue ;
		b.push_back({i,mp[a[i]].back()}) ;
		st.insert(a[i]) ;
	}
	merge(b) ;//区间合并 
	int t = b.size() - 1 ;
	LL ans = qmi(2,t,mod) ;//快速幂 
	cout << ans << endl ;
}
