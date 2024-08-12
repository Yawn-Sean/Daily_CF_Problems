#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	i64 k;
	cin >> k;
	i64 x = 9, start = 1;
	i64 d = 1;
	while (k - d * x >= 0) {
		k -= d * x;
		x *= 10;
		d ++;
		start *= 10;
	}
	i64 order = k / d;
	i64 rem = k % d;
	start += order;
	start --;
	if (rem == 0) {
		cout << to_string(start).back() << endl;
	} else {
		start ++;
		cout << to_string(start)[rem - 1] << endl;
	}
	return 0;
}
