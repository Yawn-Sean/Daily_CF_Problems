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
	int n, x, y;
	cin >> n >> x >> y;
	vector<PII>a(n + 1);
	vector<int>s(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first, sum += a[i].first;
		s[i] = sum;
		a[i].second = i;
	}
	sort(a.begin() + 1, a.end());

	vector<int>rr(n + 1);
	rr[n] = a[n].first;
	for (int i = n - 1; i >= 1; i--) rr[i] = max(rr[i + 1], (n - i + 1) * a[i].first);
	for (int i = 1; i <= n; i++) {
		int l = i, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if ((mid - i + 1)*a[i].first >= min(x, y)) r = mid;
			else l = mid + 1;
		}
		// cout<<i<<' '<<r<<endl;
		// cout<<rr[l+1]<<endl;
		if (l != n && rr[l + 1] >= max(x, y) && ((l - i + 1)*a[i].first >= min(x, y))) {
			cout << "Yes" << endl;
			vector<int>ans;
			for (int j = n; j >= l + 1; j--) {
				ans.push_back(a[j].second);
				if ((n - j + 1)*a[j].first >= max(x, y)) break;
			}
			if (x < y) {
				cout << r - i + 1 << ' ' << ans.size() << endl;
				for (int j = i; j <= r; j++) cout << a[j].second << " ";
				cout << endl;
				for (auto x : ans) cout << x << ' ';
			} else {
				cout << ans.size() << ' ' << r - i + 1 << endl;
				for (auto x : ans) cout << x << ' ';
				cout << endl;
				for (int j = i; j <= r; j++) cout << a[j].second << " ";
			}
			return;
		}

		l = i, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if ((mid - i + 1)*a[i].first >= max(x, y)) r = mid;
			else l = mid + 1;
		}
		// cout<<i<<' '<<r<<endl;
		// cout<<rr[l+1]<<endl;
		if (l != n && rr[l + 1] >= min(x, y) && ((l - i + 1)*a[i].first >= max(x, y))) {
			cout << "Yes" << endl;
			vector<int>ans;
			for (int j = n; j >= l + 1; j--) {
				ans.push_back(a[j].second);
				if ((n - j + 1)*a[j].first >= min(x, y)) break;
			}
			if (x > y) {
				cout << r - i + 1 << ' ' << ans.size() << endl;
				for (int j = i; j <= r; j++) cout << a[j].second << " ";
				cout << endl;
				for (auto x : ans) cout << x << ' ';
			} else {
				cout << ans.size() << ' ' << r - i + 1 << endl;
				for (auto x : ans) cout << x << ' ';
				cout << endl;
				for (int j = i; j <= r; j++) cout << a[j].second << " ";
			}
			return;
		}
	}
	cout << "No" << endl;
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin>>T;
	while (T--) solve();

	return 0;
}
