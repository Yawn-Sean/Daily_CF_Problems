#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		c=ceil(n/m)
		n*n-c*c
		(n+c)(n-c)=x
		ab = x
		a=n+c
		b=n-c
		
		n=(a+b)/2
		c=(a-b)/2
		m=(a+b)/(a-b)
	*/
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 0) {
			cout << "1 1\n";
		} else {
			bool find = false;
			for (int i = 1; i * i < x; i++) {
				if (x % i == 0) {
					int a = x / i, b = i;
					int n = (a + b) / 2;
					int m = (a + b) / (a - b);
					if (1ll * n * n - 1ll * (n / m) * (n / m) == x) {
						find = true;
						cout << n << ' ' << m << '\n';
						break;
					}
				}
			}
			if (not find) {
				cout << "-1\n";
			}
		}
	}
	
	return 0;
}
