#include<bits/stdc++.h>
using namespace std;
int x[5], y[5];
int main() {
	for (int i = 1; i <= 3; i++) cin >> x[i] >> y[i];
	if ((x[1] == x[2] && x[2] == x[3]) || (y[1] == y[2] && y[2] == y[3])) cout << 1;
	else {
		for (int i = 1; i <= 3; i++) {
			for (int j = i + 1; j <= 3; j++) {
				int k = 1 + 2 + 3 - i - j;
				if (x[i] == x[j] && (y[k] <= min(y[i], y[j]) || y[k] >= max(y[i], y[j]))) {
					cout << 2;
					return 0;
				}
				if (y[i] == y[j] && (x[k] <= min(x[i], x[j]) || x[k] >= max(x[i], x[j]))) {
					cout << 2;
					return 0;
				}
			}
		}
		cout<<3;
	}
	return 0;
}
