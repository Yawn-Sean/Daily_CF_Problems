#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    auto S = s.find_first_of('M');
    if (S == string::npos) { println("0"); return; }
    for (auto i = S; i < s.size(); ++i) {
        if (s[i] == 'F') {
            ans = max(ans + 1, cnt);
        } else {
            ++cnt;
        }
    }
    println("{}", ans);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
