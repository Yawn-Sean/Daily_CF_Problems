#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;
 
	while (t --) {
		int n;
		cin >> n;
		cout << (n < 3 ? 0 : n - (n + 1) / 3) << '\n';
	}
 
	return 0;
}