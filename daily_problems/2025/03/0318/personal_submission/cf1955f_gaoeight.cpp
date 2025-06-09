
void solve() {
	int p[5];
	cin >> p[1] >> p[2] >> p[3] >> p[4] ;
	int ans = p[4] / 2 + p[1] / 2 + p[2] / 2 + p[3] / 2;
	if(p[1] % 2 == 1 && p[2] % 2 == 1 && p[3] % 2 == 1) {
		ans++;
	}
	cout << ans << "\n";

}
int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
