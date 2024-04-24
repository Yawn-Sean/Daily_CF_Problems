#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);

struct node {
    i64 s, h, p;

    bool operator<(const node& o) const{
        return (s * o.h > h * o.s);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<string> str(n);
    vector<node> cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        for (char c : str[i]) {
            if (c == 's') ++cnt[i].s;
            else {
                ++cnt[i].h;
                cnt[i].p += cnt[i].s;
            }
        }
    }
    sort(cnt.begin(), cnt.end());
    i64 ans = 0, tot_h = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += cnt[i].p + cnt[i].s * tot_h;
        tot_h += cnt[i].h;
    }
    cout << ans << '\n';
}

int main() {
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}