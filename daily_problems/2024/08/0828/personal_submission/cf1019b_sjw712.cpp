const int N = 100010;
int vis[N], n;
int ask(int x){
	if(vis[x]) return vis[x];
	int res1, res2;
	cout << "? " << x << endl;
	cin >> res1;
	cout << "? " << x + n / 2 << endl;
	cin >> res2;
	return vis[x] = res1 - res2;
}
void solve(){
	cin >> n;
	if(n % 4 != 0) return cout << "! -1" << endl, void();
	if(ask(1) == 0) return cout << "! 1" << endl, void();
	int l = 1, r = 1 + n / 2;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(ask(mid) == 0) return cout << "! " << mid << endl, void();
		else{
			if(ask(mid) * ask(l) < 0) r = mid;
			else l = mid;
		}
	}
}
