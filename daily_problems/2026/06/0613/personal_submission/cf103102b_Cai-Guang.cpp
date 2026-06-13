#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    string s;
    cin >> s;

    int cnt1 = 0;
    i64 rev = 0;
    for (auto x : s) {
        if (x == '1') {
            cnt1 ++;
        } else {
            rev += cnt1;
        }
    }

    if (rev % 3) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
    // cout << rev << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	
	// cin >> t;
	
	while (t --) {
		solve();
	}
} 
