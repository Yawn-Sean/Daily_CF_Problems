int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	cout << (binpow(3, 3 * n, MOD) - binpow(7, n, MOD) + MOD) % MOD << endl;
	return 0;
}
