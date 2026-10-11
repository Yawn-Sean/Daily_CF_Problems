#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int leaf = 2;

	for (int i = 3; i <= n; i ++) {
		cout << "? " << 1 << ' ' << leaf << ' ' << i << endl;
		int x; cin >> x;
		if (x) leaf = i;
	}

	cout << "! " << leaf;

	return 0;
}