#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
    int x = 0; bool f = 0; char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> a, b;

int main() {
    int n = rd(), m = rd();
    rep(i, 1, m) {
        int u = rd(), v = rd();
        u < v ? a.eb(i) : b.eb(i);
    }
    puts("YES");
    if (a.size() < b.size()) swap(a, b);
    printf("%d\n", (int)a.size());
    for (auto x : a) printf("%d ", x);
    return 0;
}
