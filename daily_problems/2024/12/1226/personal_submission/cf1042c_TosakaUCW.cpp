#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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
    
    vector<int> a(n + 1);
    vector<int> pos, zero, neg;

    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (a[i] == 0) zero.eb(i);
        if (a[i] < 0) neg.eb(i);
        if (a[i] > 0) pos.eb(i);
    }

    std::sort(neg.begin(), neg.end(), [&](int x, int y) {
        return a[x] > a[y];
    });

    while (neg.size() > 1) {
        int i = neg.back(); neg.pop_back();
        int j = neg.back(); neg.pop_back();
        pos.eb(j);
        printf("1 %d %d\n", i, j);
    }
    while (pos.size() > 1) {
        int i = pos.back(); pos.pop_back();
        int j = pos.back(); pos.pop_back();
        pos.eb(j);
        printf("1 %d %d\n", i, j);
    }
    while (zero.size() > 1) {
        int i = zero.back(); zero.pop_back();
        int j = zero.back(); zero.pop_back();
        zero.eb(j);
        printf("1 %d %d\n", i, j);
    }

    if (neg.size() and zero.size()) {
        printf("1 %d %d\n", neg[0], zero[0]);
        if (pos.size()) {
            printf("2 %d\n", zero[0]);
        }
    }
    if (neg.size() and !zero.size()) {
        printf("2 %d\n", neg[0]);
    }
    if (!neg.size() and zero.size()) {
        if (pos.size()) {
            printf("2 %d\n", zero[0]);
        }
    }
    if (!neg.size() and !zero.size()) {

    }

}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
