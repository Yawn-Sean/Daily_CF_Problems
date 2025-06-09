#include <bits/stdc++.h>
using namespace std;
/* clang-format off */
template<class T1, class T2> bool cmin(T1 &x, const T2 &y) { if (y<x) { x=y; return 1; } return 0; }
template<class T1, class T2> bool cmax(T1 &x, const T2 &y) { if (x<y) { x=y; return 1; } return 0; }
/* clang-format off */
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<int,2>> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i ++) {
        int x = s[i] - '0';
        pre[i + 1][x] = max(pre[i][x], pre[i][!x] + 1);
        pre[i + 1][!x] = pre[i][!x];
    }
    for (int i = n - 1; i >= 0; i --) {
        int x = s[i] - '0';
        suf[i][x] = max(suf[i+1][x], suf[i+1][!x] + 1);
        suf[i][!x] = suf[i+1][!x];
    }

    int ans = 1;
    for (int i = 1, j; i < n; i = j) {
        j = i + 1;
        if (s[i] != s[i-1]) continue;
        while (j < n and s[j] != s[j - 1]) j ++;
        //reverse [i, j)
        int x = s[i] - '0';
        int y = (j - i) % 2 ? x : !x;
        ans = max(ans, pre[i][x] + j - i + suf[j][y]);
    }
    for (int i = 0; i < n; i ++) {
        int x = s[i] - '0';
        ans = max(ans, pre[i + 1][x] + suf[i+1][!x]);
        ans = max(ans, pre[i + 1][!x] + suf[i+1][x]);
    }
    cout << ans << "\n";

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	solve();
	return 0;
}