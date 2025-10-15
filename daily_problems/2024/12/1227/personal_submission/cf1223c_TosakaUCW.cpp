#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    vector<int> p(n);
    for (auto &x : p) x = read() / 100;
    std::sort(p.rbegin(), p.rend());

    int x = read(), a = read();
    int y = read(), b = read();

    if (x > y) {
        swap(x, y);
        swap(a, b);
    }

    int k = read();

    auto judge = [&](int m) {
        int cab = 0, ca = 0, cb = 0;
        for (int i = 1; i <= m; i++) {
            if (i % a == 0 and i % b == 0) cab++;
            else if (i % a == 0) ca++;
            else if (i % b == 0) cb++;
        }
        int res = 0;
        for (auto t : p) {
            if (cab) cab--, res += t * (x + y);
            else if (cb) cb--, res += t * y;
            else if (ca) ca--, res += t * x;
        }

        return res >= k;
    };

    int ans = -1;
    for (int l = 1, r = n; l <= r; ) {
        int mid = l + r >> 1;
        if (judge(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
