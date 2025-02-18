#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	if (n > 1LL * k * k - k) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 1, cnt = 0; i <= k && cnt < n; i ++) {
			for (int j = i + 1; j <= k && cnt < n; j ++, cnt += 2) {
				cout << i << " " << j << endl;
				if (cnt + 1 < n) {
					cout << j << " " << i << endl;
				}
			}
		}
	}
	return 0;
}
