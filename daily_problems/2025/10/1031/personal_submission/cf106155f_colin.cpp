#include <bits/stdc++.h>
using namespace std;

inline void work() {
	int n; cin >> n;
	int cnt1 = 0, cnt2 = 0;
	while (n--) {
		string s, t = "";
		cin >> s;
		for (auto x : s) if (x != '=') t += x;
		if (t == "xxx") ++cnt1;
		else if (t == "xx." || t == ".xx") ++cnt2;
	}
	if (cnt2 & 1) puts("Monocarp");
	else puts((cnt1 & 1) ? "Monocarp" : "Polycarp");
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t; while (t--) work();
	return 0;
}