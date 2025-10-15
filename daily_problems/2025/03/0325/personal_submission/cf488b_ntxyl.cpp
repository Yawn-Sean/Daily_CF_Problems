#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int>a(5);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.begin() + 1 + n);
	if (n == 4) {
		// for(int i=1;i<=n;i++) cout<<a[i]<<endl;
		if (a[1] * 3 == a[4] && (a[2] + a[3]) == 4 * a[1]) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else if (n == 3) {
		bool st = 0;
		vector<int>b(5);

		b = a;
		b[4] = a[1] * 3;
		int x = b[4];
		sort(b.begin() + 1, b.end());
		if (b[1] * 3 == b[4] && (b[2] + b[3]) == 4 * b[1]) {
			cout << "YES" << endl;
			cout << x << endl;
			return;
		}

		b = a;
		b[4] = (a[3] + a[1] - a[2]);
		x = b[4];
		sort(b.begin() + 1, b.end());
		if (b[1] * 3 == b[4] && (b[2] + b[3]) == 4 * b[1]) {
			cout << "YES" << endl;
			cout << x << endl;
			return;
		}
		b = a;
		if (b[3] % 3 == 0) {
			b[4] = b[3] / 3;
			x = b[4];
			sort(b.begin() + 1, b.end());
			if (b[1] * 3 == b[4] && (b[2] + b[3]) == 4 * b[1]) {
				cout << "YES" << endl;
				cout << x << endl;
				return;
			}
		}
		cout << "NO" << endl;
	} else if (n == 2) {
		vector<int>b(5);
		b = a;

		int x = a[1], y = a[2];
		for (int i = 1; i <= 4; i++) {
			for (int j = i + 1; j <= 4; j++) {
				if (i == 1 && j == 4) {
					if (y / 3 == x && y % 3 == 0) {
						cout << "YES" << endl;
						cout << x << endl;
						cout << y << endl;
					}
				} else if (i == 1 && (j == 3 || j == 2)) {
					vector<int>b;
					b.push_back(0);
					b.push_back(x);
					b.push_back(y);
					b.push_back(x * 3);
					b.push_back(4 * x - y);
					sort(b.begin() + 1, b.end());
					if (b[1] * 3 == b[4] && (b[2] + b[3]) == 4 * b[1]) {
						cout << "YES" << endl;
						cout << x * 3 << endl;
						cout << 4 * x - y << endl;
						return;
					}
				} else if ((i == 2 || i == 3) && j == 4) {
					if (y % 3) continue;
					vector<int>b;
					b.push_back(0);
					b.push_back(x);
					b.push_back(y);
					b.push_back(y / 3);
					b.push_back(4 * (y / 3) - x);
					sort(b.begin() + 1, b.end());
					if (b[1] * 3 == b[4] && (b[2] + b[3]) == 4 * b[1]) {
						cout << "YES" << endl;
						cout << y / 3 << endl;
						cout << 4 * (y / 3) - x << endl;
						return;
					}
				}
			}
		}
		cout << "NO" << endl;
	} else if (n == 1) {
		cout << "YES" << endl;
		cout << a[1] << endl;
		cout << a[1] * 3 << endl;
		cout << a[1] * 3 << endl;
	} else {
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << endl;
		cout << 3 << endl;
		cout << 3 << endl;
	}
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin>>T;
	while (T--) solve();

	return 0;
}
