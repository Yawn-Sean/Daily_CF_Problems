#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	int n = s.size();
	int ans = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'M') {
			cnt++;
		} else if (cnt > 0) {
			ans = max(ans + 1, cnt);
		}
	}
	cout << ans << '\n';
    return 0;
}
