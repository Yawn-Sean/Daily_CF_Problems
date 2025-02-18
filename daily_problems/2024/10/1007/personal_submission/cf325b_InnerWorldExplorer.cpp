int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	i64 n;
	cin >> n;
	bool f = false;
	for (int i = 0; i < 60; i ++){
		i64 x = (1LL << i);
		i64 l = 0, r = min(1LL << 31, n / max(x - 1, 1LL));
		while (l < r){
			i64 mid = (l + r) / 2;
			if (mid * (mid - 1) / 2 + mid * (x - 1) < n){
				l = mid + 1;
			}else{
				r = mid;
			}
		}
		if (l % 2 && (l - 1) * l / 2 + l * (x - 1) == n){
			f = true;
			cout << l * x << endl;
		}
	}
	if (!f) cout << -1 << endl;
	return 0;
}
