#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, n;
	cin >> n >> a >> b;
	if ((a != 1 && b != 1) || (a == 1 && b == 1 && n >= 2 && n <= 3)) {
		return cout << "NO" << endl, 0;
	}
	cout << "YES" << endl;
	if (a > 1) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cout << int(i >= a - 1 && j >= a - 1 && i != j);
			}
			cout << endl;
		}
	} else if (b > 1) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cout << int(((i < b - 1) || (j < b - 1) || (j > i && i + 1 >= b && j != i + 1) || (i > j && j + 1 >= b && i != j + 1)) && i != j);
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cout << int((j == i + 1) || (i == j + 1));
			}
			cout << endl;
		}
	}
	return 0;
}
