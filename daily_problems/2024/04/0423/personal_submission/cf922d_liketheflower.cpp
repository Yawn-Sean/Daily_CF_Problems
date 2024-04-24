// https://codeforces.com/contest/922/submission/257920198
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = std::pair<int, int>;

int main() {
    int n; cin >> n;
    vector<string> strs(n);
    vector<LL> cnt_s(n), cnt_h(n);
    vector<int> ids(n);
    for (int i = 0; i < n; ++i) {
	cin >> strs[i];
	ids[i] = i;
	for (auto c: strs[i]) {
	    if (c == 's') {
		++cnt_s[i];
	    } else {
		++cnt_h[i];
	    }
	}
    }
    sort(begin(ids), end(ids), [&](int i, int j) {
	    // SHi + SHj + cnt_s[i] * cnt_h[j] > SHi + SHj + cnt_s[j] * cnt_h[i]
	    // // cnt_s[i] * cnt_h[j] > cnt_s[j] * cnt_h[i]
	    return cnt_s[i] * cnt_h[j] > cnt_s[j] * cnt_h[i];
	    });

    LL ret = 0, s = 0;
    for (auto i : ids) {
	for (auto c : strs[i]) {
	    if (c == 's') {
		s++;
	    } else {
		ret += s;
	    }
	}
    }
    cout << ret << endl;
    return 0;
}
