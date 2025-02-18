struct Node{
	int c, p, id;
	bool operator>(const Node& t) const{
		if(p != t.p) return p > t.p;
		if(c != t.c) return c < t.c;
	}
};
void solve(){
	int n, k, ans = 0;
	cin >> n;
	vector<Node> a(n);
	set<pii> s;
	for(int i = 0; i < n; i ++){
		cin >> a[i].c >> a[i].p;
		a[i].id = i + 1;
	}
	cin >> k;
	for(int i = 0; i < k; i ++){
		int x;
		cin >> x;
		s.insert({x, i + 1});
	}
	sort(a.begin(), a.end(), greater());
	vector<pii> v;
	for(auto &[c, p, id] : a){
		auto it = s.lower_bound(make_pair(c, 0));
		if(it != s.end()){
			ans += p;
			s.erase((*it));
			v.push_back({id, (*it).y});
		}
	}
	cout << v.size() << " " << ans << '\n';
	for(int i = 0; i < v.size(); i ++) cout << v[i].x << " " << v[i].y << '\n';
}
