#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, string> PII;

const int N = 1e5 + 10;

void solve() {
	int k;
	cin >> k;
	// cout<<k<<endl;
	cin.get();
	string s;
	getline(cin, s);
	// cout<<s<<endl;
	int n = s.size();
	// cout<<n<<endl;
	vector<PII>ss;
	string t = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ' || s[i] == '-') {
			if (s[i] == '-') t += s[i];
			ss.push_back({t.size(), t});
			t = "";
		} else t += s[i];
	}
	if (t.size()) ss.push_back({t.size(), t});
	// sort(all(ss),[&](auto x,auto y){
	//     return x.first<y.first;
	// });
	int m = ss.size();

	// for(auto [x,y]:ss) cout<<x<<" "<<y<<endl;

	int l = 1, r = 1e6;
	auto check = [&](int x)->bool{
		int t = 1, tt = 0;
		for (int i = 0; i < m; i++) {
			auto [sz, u] = ss[i];
			if (i != m - 1 && u[u.size() - 1] != '-') sz++;
			if (sz > x) return 0;
			if (tt + sz > x) t++, tt = sz;
			else tt += sz;
		}
		// cout<<k<<' '<<t<<endl;
		if (t <= k) return 1;
		else return 0;
	};
	// cout<<check(10)<<endl;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin>>T;
	while (T--) solve();

	return 0;
}
