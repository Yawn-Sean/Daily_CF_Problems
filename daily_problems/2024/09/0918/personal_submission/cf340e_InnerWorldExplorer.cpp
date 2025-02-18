constexpr unsigned MOD = 1000000007;
using Z = ModInt<MOD>;

vector<int> fac(2001);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	//x0 : pos already be occupied
	//x1 : not
	set<int> used_num, used_pos;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (a[i] != -1) {
			used_num.insert(a[i]);
			used_pos.insert(i + 1);
		}
	}

	int x0 = 0, x1 = 0;
	for (int i = 1; i <= n; i ++) {
		if (!used_num.count(i)) {
			if (!used_pos.count(i)) {
				x1 ++;
			} else {
				x0 ++;
			}
		}
	}

	fac[0] = 1;
	for (int i = 1; i <= n; i ++) {
		fac[i] = 1LL * fac[i - 1] % MOD * i % MOD;
	}

	int cnt = x0 + x1;
	Z ans = 0;
	for (int i = 1; i <= x1; i ++) {
		ans += (i % 2 ? 1 : -1) * Z(C(x1, i)) * Z(fac[cnt - i]);
	}
	cout << fac[cnt] - ans << endl;
	return 0;
}
