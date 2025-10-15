#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1036/B
//格式化： ctrl+shift+ a

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		ll n, m, k;
		cin >> n >> m >> k;

		if (k < max(n, m))
			cout << -1 << '\n';
		else if ((n + m) % 2)
			cout << k - 1 << '\n';
		else if (n % 2 == k % 2)
			cout << k << '\n';
		else
			cout << k - 2 << '\n';
	}

	return 0;
}
