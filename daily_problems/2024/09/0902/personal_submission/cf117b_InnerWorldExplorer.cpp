#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, mod;
	cin >> a >> b >> mod;
	for (int x = 0; x <= min(mod, a); x ++) {
		long long dm = 1LL * x * 1000000000;
		long long lb = dm / mod;
		if (lb * mod < dm && (lb + 1) * mod > dm + b) {
			cout << "1\n" << setfill('0') << setw(9) << x << endl;
			return 0;
		}
	}
	cout << 2 << endl;
	return 0;
}
