#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	i64 tot = 0;
	int x, d;
	for (int i = 0; i < m; i ++) {
		cin >> x >> d;
		tot += x * n;
		if (d >= 0) {
			tot += 1LL * d * (n - 1) * n / 2;
		} else {
			if (n % 2){
				tot += 1LL * d * (n / 2) * (n / 2 + 1);
			}else{
				i64 tmp = 1LL * (n / 2) * (n / 2 + 1) / 2;
				tot += (2 * tmp - n / 2) * d;
			}
		}
	}

	cout << fixed << setprecision(10) << 1.0 * tot / n << endl;
	return 0;
}
