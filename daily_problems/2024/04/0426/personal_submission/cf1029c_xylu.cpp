#include <bits/stdc++.h>
using namespace std;

// 某个下标的删除等于前后缀的合并
int main() {
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> inter(n), suf(n+1, {0, 1e9});
    for (int i = 0; i < n; i++) {
        cin >> inter[i].first >> inter[i].second;
    }
    for (int i = n-1; i >= 0; i--) {
        suf[i].first = max(suf[i+1].first, inter[i].first);
        suf[i].second = min(suf[i+1].second, inter[i].second);
    }
    pair<int, int> pre = {0, 1e9};
    for (int i = 0; i < n; i++) {
        ans = max(ans, max(0, min(suf[i+1].second, pre.second) - max(suf[i+1].first, pre.first)));
        pre.first = max(pre.first, inter[i].first);
        pre.second = min(pre.second, inter[i].second);
    }
    cout << ans << endl;

    return 0;
}
