#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int N = 10;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int zero = 0, one = (1 << 10) - 1;
	char op;
	int x;
	while (n -- ) {
		cin >> op >> x;
		if (op == '|') {
			zero |= x; one |= x;
		} else if (op == '&') {
			zero &= x; one &= x;
		} else {
			zero ^= x; one ^= x;
		}
	}
	int X = (1 << 10) - 1, Y = 0, Z = 0;
	for (int i = 0; i < N; i ++) {
		int b0 = (zero >> i) & 1, b1 = (one >> i) & 1;
		if (b0 == b1) {
			if (b0 == 0) {
				X ^= 1 << i;
			} else {
				Y |= 1 << i;
			}
		} else if (b0 == 1 && b1 == 0) {
			Z |= 1 << i;
		}
	}
	cout << 3 << endl;
	cout << "& " << X << endl;
	cout << "| " << Y << endl;
	cout << "^ " << Z << endl;
	return 0;
}
