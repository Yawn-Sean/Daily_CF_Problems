void solve(){
	int la, ra, ta, lb, rb, tb;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	if(lb < la){
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}
	int g = gcd(ta, tb);
	int x = (lb - la) % g;
	int ans = 0;
	ans = max(ans, min(rb - lb + 1, ra - la + 1 - x));
	x = g - x;
	ans = max(ans, min(ra - la + 1, rb - lb + 1 - x));
	cout << ans << '\n';
}
