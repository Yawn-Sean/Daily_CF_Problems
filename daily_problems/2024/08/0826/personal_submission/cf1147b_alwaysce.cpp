#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(false);
	
    int n, m;
    cin >> n >> m;
	
	vector<pair<int,int>> segs;
	set<pair<int,int>> vis;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (a > b) { swap(a, b); }
		segs.push_back({a, b});
		vis.insert({a, b});
	}

	// m * (<= n的质因数个数)	
	int tmp = n;
	for (int i = 2; i <= n; i++) {
		if (tmp % i == 0) {
			while (tmp % i == 0) {
				tmp /= i;
			}
			int x = n / i;
			bool ok = true;
			for (int j = 0; j < m; j++) {
				int nl = (segs[j].first + x) % n;
				int nr = (segs[j].second + x) % n;
				if (nl > nr) { swap(nl, nr); }
				if (vis.find({nl, nr}) == vis.end()) {
					ok = false;
					break;
				}
			}
			if (ok) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
    return 0;   
}
