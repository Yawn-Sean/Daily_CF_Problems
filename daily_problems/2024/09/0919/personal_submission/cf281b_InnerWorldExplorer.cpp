#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, y, n;
	cin >> x >> y >> n;
	long long p = x, q = y;
	int de = 1, nu = 0;
	for (int b = n; b >= 1; b --) {
		int v = 1LL * b * x / y;
		for (auto a : {v + 1, v}) {
			//abs(a/b - x/y) < p/q
			//abs((ay-bx) / by) < p/q
			long long np = abs(1LL * b * x - 1LL * a * y), nq = 1LL * b * y;
			if (np * q <= nq * p) {
				p = np;
				q = nq;
				de = b;
				nu = a;
			}
		}
	}
	cout << nu << "/" << de << endl;
	return 0;
}
