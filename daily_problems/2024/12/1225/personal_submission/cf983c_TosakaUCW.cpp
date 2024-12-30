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

const int INF = 1e18;

void solve() {
    int x = read();
    if (x == 0) {
        puts("1 1");
        return;
    }
    if (x == 1) {
        puts("-1");
        return;
    }

    for (int i = 1; i * i < x; i++) {
        if (x % i != 0) continue;
        int a = x / i, b = i;
        int n = (a + b) / 2, m = (a + b) / (a - b);
        if (x == n * n - (n / m) * (n / m)) {
            cout << n << " " << m << '\n';
            return;
        }
    }
    puts("-1");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
